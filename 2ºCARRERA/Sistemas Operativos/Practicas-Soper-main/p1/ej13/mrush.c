/**
 * @file mrush.c
 * @author Sergio Hidalgo & Miguel Ibáñez
 * @brief Main that initiates the process of the miner and the process of the monitor.
 * @version 1.0
 * @date 2022-02-22
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <string.h>
#include "pow.h"

void *mining(void *argv);
int thread_init(long int threads, void *sol, long int obj, pthread_t *h);
int miner(long int obj, long int rounds, long int threads, int fdin[2], int fdout[2]);
int monitor(long int obj, long int rounds, int fdin[2], int fdout[2]);

int monitor(long int obj, long int rounds, int fdin[2], int fdout[2])
{
    ssize_t nbytes;
    int i = 0;
    char str[MAX_STR_LGH];
    long int sol, obj_m;

    if (fdin == NULL || fdout == NULL || rounds <= 0 || obj < 0 || obj > POW_LIMIT)
    {
        return EXIT_FAILURE;
    }

    /*Loop that will repeat for all the rounds*/
    while (i < rounds)
    {

        /*First, it reads the pipe input*/
        nbytes = 0;
        do
        {
            nbytes = read(fdout[0], str, sizeof(str));
            if (nbytes == -1)
            {
                perror("read");
                return EXIT_FAILURE;
            }
            if (nbytes > 0)
            {
                /*It will get the solution and the objective provided by the miner*/
                sscanf(str, "%ld|%ld", &sol, &obj_m);
                break;
            }
        } while (nbytes != 0);

        /*It is printed the status of the solution*/
        if (pow_hash(sol) == obj_m && obj == obj_m)
        {
            printf("Solution accepted: %08ld --> %08ld\n", obj_m, sol);
            obj = sol;
        }
        else
        {
            printf("Solution rejected: %08ld !-> %08ld\n", obj_m, sol);
            obj = -1;
        }

        /*The monitor sends through the output pipe the new objective
        (-1 if it was incorrect, or the solution provided by the miner if it was correct)*/
        sprintf(str, "%ld", obj);

        nbytes = write(fdin[1], str, strlen(str) + 1);
        if (nbytes == -1)
        {
            perror("write");
            return EXIT_FAILURE;
        }

        if (obj == -1)
        {
            sleep(0);
            return EXIT_SUCCESS;
        }


        sleep(0);

        i++;
    }

    return EXIT_SUCCESS;
}

void *mining(void *argv)
{
    long int aux = 0, count = 0;
    long int *sol = NULL;
    long int obj;

    if (argv == NULL)
    {
        return NULL;
    }

    /*Scans the address of the solution pointer, the objective, and the number of thread*/
    sscanf(argv, "%p|%ld|%ld", (void **)&sol, &obj, &count);

    if (sol == NULL || obj < 0 || obj > POW_LIMIT || count <= 0)
    {
        return NULL;
    }

    /*Count is used to calculate the segment that this thread is going to work on*/
    aux = POW_LIMIT / (count);

    if (count % 2 != 0)
    {

        aux = POW_LIMIT - aux;

        if (count != 1)
        {
            aux = aux - (POW_LIMIT / (count + 3));
        }
    }
    else
    {
        aux = POW_LIMIT - aux * (count - 1);
        aux = aux + (POW_LIMIT / (count + 1));
    }

    /*The thread is going to try all the values possibles*/
    while (aux <= POW_LIMIT && (pow_hash(aux) != (long int)obj) && (pow_hash(*sol) != (long int)obj))
    {
        aux++;
    }

    /*If the thread leaves the loop because it has found the value*/
    if (pow_hash(aux) == (long int)obj)
    {
        *sol = aux;
        pthread_exit(EXIT_SUCCESS);
    }

    pthread_exit(EXIT_SUCCESS);
}

int thread_init(long int threads, void *sol, long int obj, pthread_t *h)
{
    int i, err;
    char *argss;

    if (threads <= 0 || sol == NULL || obj < 0 || obj > POW_LIMIT || h == NULL)
    {
        return EXIT_FAILURE;
    }

    /*Transform the objective and the solution memory adresses into a string,
    because pthread_create only acepts a string for parameters*/
    argss = (char *)calloc(sizeof(char), MAX_STR_LGH);
    if (argss == NULL)
    {
        return EXIT_FAILURE;
    }

    /*This loops repeats until all the threads are created*/
    for (i = 0; i < threads; i++)
    {

        sprintf(argss, "%p|%ld|%ld", sol, obj, (long)i + 1);

        err = pthread_create(&h[i], NULL, mining, argss);
        if (err != 0)
        {
            perror("pthread_create");
            return EXIT_FAILURE;
        }

        /*All the threads will wait (but when 1 thread ends, all the threads will stop, because how the function
        mining works)*/
        err = pthread_join(h[i], NULL);
        if (err != 0)
        {
            perror("pthread_create");
            return EXIT_FAILURE;
        }
    }

    free(argss);

    return 0;
}

int miner(long int obj, long int rounds, long int threads, int fdin[2], int fdout[2])
{
    int i = 0;
    pthread_t *h;
    long int sol = 0;
    char str[MAX_STR_LGH];
    ssize_t nbytes;

    if (rounds <= 0 || threads <= 0 || obj < 0 || obj > POW_LIMIT || fdin == NULL || fdout == NULL)
    {
        exit(EXIT_FAILURE);
    }

    /*Alloc the memory for array of threads*/
    h = (pthread_t *)malloc(sizeof(pthread_t) * (threads));
    if (h == NULL)
    {
        exit(EXIT_FAILURE);
    }

    /*This loops repeats until all the rounds are done*/
    for (i = 0; i < rounds; i++)
    {

        if (thread_init(threads, (void *)&sol, obj, h) == EXIT_FAILURE)
        {
            return EXIT_FAILURE;
        }

        /*Writes the result on a string and send it through the pipe to the other process*/
        sprintf(str, "%ld|%ld", sol, obj);

        nbytes = write(fdin[1], str, strlen(str) + 1);
        if (nbytes == -1)
        {
            perror("write");
            return EXIT_FAILURE;
        }

        /*Reads the answer from the other process on another pipe*/
        do
        {
            nbytes = 0;
            nbytes = read(fdout[0], str, sizeof(str));
            if (nbytes == -1)
            {
                perror("read");
                exit(EXIT_FAILURE);
            }
            if (nbytes > 0)
            {

                sscanf(str, "%ld", &sol);
                break;
            }
        } while (nbytes != 0);

        /*If its not valid, the miner stops*/
        if (sol == -1)
        {
            printf("The solution has been invalidated\n");
            return EXIT_FAILURE;
        }

        obj = sol;
    }

    free(h);

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    long int obj, rounds, threads;
    pid_t pid, pid2;
    int min, moni;
    int fdmin[2], fdmoni[2];
    int pipe_status;

    if (argc != 4)
    {
        printf("\nParameters doesn't match <obj> <rounds> <threads>\n");
        exit(EXIT_FAILURE);
    }

    obj = atol(argv[1]);
    rounds = atol(argv[2]);
    threads = atoi(argv[3]);

    /*It open 2 pipes*/
    pipe_status = pipe(fdmin);
    if (pipe_status == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pipe_status = pipe(fdmoni);
    if (pipe_status == -1)
    {
        close(fdmin[0]);
        close(fdmin[1]);
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    /*Then creates 2 process*/
    pid = fork();

    if (pid < 0)
    {
        close(fdmin[0]);
        close(fdmin[1]);
        close(fdmoni[0]);
        close(fdmoni[1]);
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        /*The miner (makes the one file descriptor for reading and another for writing)*/
        close(fdmin[0]);
        close(fdmoni[1]);

        min = miner(obj, rounds, threads, fdmin, fdmoni);

        close(fdmin[1]);
        close(fdmoni[0]);

        if (min < 0)
        {
            printf("Miner exited unexpectedly\n");
            exit(EXIT_FAILURE);
        }

        printf("Miner exited with status %d\n", min);
    }
    else if (pid > 0)
    {
        pid2 = fork();

        if (pid2 < 0)
        {
            close(fdmin[0]);
            close(fdmin[1]);
            close(fdmoni[0]);
            close(fdmoni[1]);
            perror("fork2");
            exit(EXIT_FAILURE);
        }
        else if (pid2 == 0)
        {
            /*The monitor (it does the same to form 2 pipes)*/
            close(fdmoni[0]);
            close(fdmin[1]);

            moni = monitor(obj, rounds, fdmoni, fdmin);
            

            close(fdmin[0]);
            close(fdmoni[1]);


            if (moni < 0)
            {
                printf("Monitor exited unexpectedly\n");
                exit(EXIT_FAILURE);
            }

            printf("Monitor exited with status %d\n", moni);
        }
        else
        {
            wait(NULL);
        }
    }
    else
    {
        wait(NULL);
    }

    pthread_exit(EXIT_SUCCESS);
}