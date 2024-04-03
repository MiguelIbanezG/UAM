/*
 * File: miner.c
 * Author: Sergio Hidalgo y Miguel Ibáñez
 */
#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include "pow.h"

int thread_init(long int threads, void *sol, long int obj, pthread_t *h);
long miner_init(long int obj, long int threads);
void *mining(void *argv);

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
    argss = (char *)calloc(sizeof(char), MAX_MESSAGE);
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

long miner_init(long int obj, long int threads)
{
    pthread_t *h;
    long int sol = 0;

    if (threads <= 0 || obj < 0 || obj > POW_LIMIT)
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

    if (thread_init(threads, (void *)&sol, obj, h) == EXIT_FAILURE)
    {
        return EXIT_FAILURE;
    }

    /*Writes the result on a string and send it through the pipe to the other process*/

    free(h);

    return sol;
}

int main(int argc, char *argv[])
{
    Message msg;
    mqd_t queue;
    int lag, rounds, i;
    long obj = 0, sol = 0;
    struct mq_attr attributes;

    if (argc != 3)
    {
    mq_unlink(MQ_NAME);

        printf("Parameters doesn't match ./miner <ROUNDS> <LAG>\n");
        exit(EXIT_FAILURE);
    }

    rounds = atoi(argv[1]);
    lag = atoi(argv[2]);

    attributes.mq_maxmsg = 10;
    attributes.mq_msgsize = sizeof(Message);

    msg  = (Message) { .obj = 0, .sol = 0, .type = "" };

    queue = mq_open(MQ_NAME,
        O_CREAT | O_WRONLY , /* This process is only going to send messages. */
        S_IRUSR | S_IWUSR, /* The user can read and write. */
        &attributes);

    if (queue == (mqd_t)-1)
    {
        fprintf(stderr, "Error opening the queue\n");
        return EXIT_FAILURE;
    }

    printf("[%d] Generating blocks...\n", getpid());

    for (i = 0; i < rounds; i++)
    {

        sol = miner_init(obj, 4);
        msg.sol = sol;
        msg.obj = obj;
        strcpy(msg.type, "Solution");
    
        if (mq_send(queue, (char *)&msg, sizeof(msg), 1) == -1)
        {
            fprintf(stderr, "Error sending message\n");
            return EXIT_FAILURE;
        }
        usleep(lag * 1000);
        obj = sol;
    }
    strcpy(msg.type, "Finish");
    msg.sol = -1;
    msg.obj = -1;

    if (mq_send(queue, (char *)&msg, sizeof(msg), 1) == -1)
    {
        fprintf(stderr, "Error sending message\n");
        return EXIT_FAILURE;
    }

    printf("[%d] Finishing\n", getpid());

    mq_unlink(MQ_NAME);

    exit(EXIT_SUCCESS);
}