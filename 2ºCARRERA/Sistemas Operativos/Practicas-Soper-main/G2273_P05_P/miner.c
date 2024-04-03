/*
 * File: miner.c
 * Author: Sergio Hidalgo y Miguel Ibáñez
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <mqueue.h>
#include <string.h>
#include <semaphore.h>
#include <sys/shm.h>
#include <pthread.h>
#include "pow.h"
#include "string.h"

#define SEM_NAME "/sem_name"

static volatile sig_atomic_t usr_signal = 0;
static volatile sig_atomic_t first = 0;

int thread_init(long int threads, void *sol, long int obj, pthread_t *h);
long miner_init(long int obj, long int threads);
void *mining(void *argv);
void miner_register(sem_t *sem, int fdout[2]);
void sigActionPrep(struct sigaction act, sigset_t mask, int sig);
void handlerusr(int sig);
void wake_miners();

void wake_miners()
{
    Info *shm_info;
    int fd_shm, i = 1;

    fd_shm = shm_open(SHM_INFO_NAME, O_RDWR, 0);
    shm_info = mmap(NULL, sizeof(Info), PROT_READ, MAP_SHARED, fd_shm, 0);
    close(fd_shm);
    if (shm_info == MAP_FAILED)
    {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    while (shm_info->pid_active_miners[i] != -1)
    {

        if (kill(shm_info->pid_active_miners[i], SIGUSR1) == -1)
        {
            perror("signal to voters");
            exit(EXIT_FAILURE);
        }
        i++;
    }

    munmap(shm_info, sizeof(Info));
}

void handlerusr(int sig)
{
    usr_signal = 1;
}

void sigActionPrep(struct sigaction act, sigset_t mask, int sig)
{

    sigemptyset(&(act.sa_mask));
    act.sa_flags = 0;

    if (sigaction(sig, &act, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    sigemptyset(&mask);
    sigaddset(&mask, sig);
    sigprocmask(SIG_BLOCK, &mask, &(act.sa_mask));
}

void miner_register(sem_t *sem, int fdout[2])
{
    int fd_shm;
    Info *shm_info;
    Miner *miner;
    Block *actual;
    sem_t *sem_empty = NULL;
    sem_t *sem_fill = NULL;
    sem_t *sem_mutex = NULL;
    ssize_t nbytes = -1;
    char str[MAX_MESSAGE], aux[MAX_MESSAGE];
    int i;

    strcpy(str, "");

    fd_shm = shm_open(SHM_INFO_NAME, O_RDWR, 0);
    if (fd_shm == -1)
    {
        close(fd_shm);

        if ((fd_shm = shm_open(SHM_INFO_NAME, O_RDWR | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR)) == -1)
        {
            perror("shm_open on creation of system");
            exit(EXIT_FAILURE);
        }

        if (ftruncate(fd_shm, sizeof(Info)) == -1)
        {
            perror("ftruncate");
            shm_unlink(SHM_INFO_NAME);
            exit(EXIT_FAILURE);
        }

        shm_info = mmap(NULL, sizeof(Info), PROT_READ | PROT_WRITE, MAP_SHARED, fd_shm, 0);

        close(fd_shm);
        if (shm_info == MAP_FAILED)
        {
            perror("mmap");
            exit(EXIT_FAILURE);
        }

        if ((fd_shm = shm_open(SHM_BLOCK_NAME, O_RDWR | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR)) == -1)
        {
            perror("shm_open opening block on miner");
            exit(EXIT_FAILURE);
        }

        if (ftruncate(fd_shm, sizeof(Block)) == -1)
        {
            perror("ftruncate");
            shm_unlink(SHM_INFO_NAME);
            exit(EXIT_FAILURE);
        }

        actual = mmap(NULL, sizeof(Block), PROT_READ | PROT_WRITE, MAP_SHARED, fd_shm, 0);

        close(fd_shm);
        if (shm_info == MAP_FAILED)
        {
            perror("mmap");
            exit(EXIT_FAILURE);
        }

        for (i = 0; i < MAX_MINERS; i++)
        {
            strcpy(shm_info->miners_shr_ids[i], "\0");
            shm_info->pid_active_miners[i] = -1;
        }
        i = 0;
    }
    else
    {
        /*Mapping of the memory segment. */
        shm_info = mmap(NULL, sizeof(Info), PROT_READ, MAP_SHARED, fd_shm, 0);
        close(fd_shm);
        if (shm_info == MAP_FAILED)
        {
            perror("mmap");
            exit(EXIT_FAILURE);
        }
        i = 1;
    }

    while (shm_info->miners_shr_ids[i][0] != '\0' && i < MAX_MINERS)
    {
        i++;
    }

    if (shm_info->miners_shr_ids[i][0] != '\0' && i >= MAX_MINERS)
    {
        printf("[%d] Couldn't join because there is %d miners already registered\n", getppid(), MAX_MINERS);

        mq_unlink(MQ_NAME);

        shmdt((void *)miner);
        munmap(shm_info, sizeof(Info));

        if (kill(getppid(), SIGUSR2) == -1)
        {
            perror("signal to voters");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    }

    sprintf(aux, "MIN:%d", getppid());
    strcpy(shm_info->miners_shr_ids[i], aux);

    if ((fd_shm = shm_open(shm_info->miners_shr_ids[i], O_RDWR | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR)) == -1)
    {
        perror("shm_open opening miner on miner");
        exit(EXIT_FAILURE);
    }

    if (ftruncate(fd_shm, sizeof(Miner)) == -1)
    {
        perror("ftruncate");
        shm_unlink(SHM_INFO_NAME);
        exit(EXIT_FAILURE);
    }

    miner = mmap(NULL, sizeof(Miner), PROT_READ | PROT_WRITE, MAP_SHARED, fd_shm, 0);

    close(fd_shm);
    if (miner == MAP_FAILED)
    {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    fflush(stdout);

    shm_info->pid_active_miners[i] = getppid();

    miner->pid = getppid();
    miner->coins = 00;
    miner->active = 1;
    miner->votes[0] = '\0';

    sem_post(sem);

    while (nbytes != 0 && strcmp(str, "Finish") != 0)
    {
        nbytes = 0;
        nbytes = read(fdout[0], str, sizeof(str));
    }

    miner->active = 0;

    sem_close(sem);
    close(fdout[0]);

    shm_unlink((const char *)shm_info->miners_shr_ids[i]);

    munmap(shm_info, sizeof(Info));
    munmap(miner, sizeof(Miner));

    if (i == 0)
    {

        munmap(actual, sizeof(Block));
        shm_unlink(SHM_INFO_NAME);
        shm_unlink(SHM_BLOCK_NAME);
    }

    exit(EXIT_SUCCESS);
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
    int threads, rounds, i, j, fd_shm;
    long obj = 0, sol = 0;
    struct mq_attr attributes;
    pid_t pid;
    char semname[MAX_MESSAGE], aux[MAX_MESSAGE];
    sem_t *sem;
    int fdout[2];
    struct sigaction act;
    sigset_t mask;
    ssize_t nbytes = 0;
    Info *shm_info;
    Block *block;
    Miner *miner;

    if (argc != 3)
    {
        printf("Parameters doesn't match ./miner <ROUNDS> <N_THREADS>\n");
        exit(EXIT_FAILURE);
    }

    rounds = atoi(argv[1]);
    threads = atoi(argv[2]);

    if (rounds < 0 || threads < 0)
    {
        printf("No negative parameters\n");
        exit(EXIT_FAILURE);
    }
    attributes.mq_maxmsg = 10;
    attributes.mq_msgsize = sizeof(Message);

    msg = (Message){.obj = 0, .sol = 0, .type = ""};

    strcpy(semname, SEM_NAME);
    strcpy(aux, "");

    sprintf(aux, "%d", getpid());

    strcat(semname, aux);

    if ((sem = sem_open(semname, O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 0)) == SEM_FAILED)
    {
        perror("sem_open");
        exit(EXIT_FAILURE);
    }

    if (pipe(fdout) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == 0)
    {
        close(fdout[1]);

        miner_register(sem, fdout);
        exit(EXIT_SUCCESS);
    }
    else if (pid > 0)
    {
        close(fdout[0]);
        queue = mq_open(MQ_NAME,
                        O_CREAT | O_WRONLY, /* This process is only going to send messages. */
                        S_IRUSR | S_IWUSR,  /* The user can read and write. */
                        &attributes);

        if (queue == (mqd_t)-1)
        {
            fprintf(stderr, "Error opening the queue\n");
            return EXIT_FAILURE;
        }

        sem_wait(sem);

        fd_shm = shm_open(SHM_INFO_NAME, O_RDWR, 0);
        shm_info = mmap(NULL, sizeof(Info), PROT_READ, MAP_SHARED, fd_shm, 0);
        close(fd_shm);
        if (shm_info == MAP_FAILED)
        {
            perror("mmap");
            exit(EXIT_FAILURE);
        }

        if (shm_info->pid_active_miners[0] == getpid())
        {
            first = 1;
        }

        fd_shm = shm_open(SHM_BLOCK_NAME, O_RDWR, 0);

        block = mmap(NULL, sizeof(Block), PROT_READ | PROT_WRITE, MAP_SHARED, fd_shm, 0);
        if (block == NULL)
        {
            perror("Mmap");
            exit(EXIT_FAILURE);
        }
        close(fd_shm);

        j = 0;

        while (shm_info->pid_active_miners[j] != getpid())
        {
            j++;
        }

        fd_shm = shm_open(shm_info->miners_shr_ids[j], O_RDWR, 0);

        if (fd_shm < 0)
        {
            perror("shm_open miner on miner");
            exit(EXIT_FAILURE);
        }

        miner = mmap(NULL, sizeof(Miner), PROT_READ | PROT_WRITE, MAP_SHARED, fd_shm, 0);
        if (miner == MAP_FAILED)
        {
            perror("mmap struct");
            exit(EXIT_FAILURE);
        }

        close(fd_shm);

            block->coins[j] = miner->coins;
            block->miners_pid[j] = miner->pid;
        for (i = 0; i < rounds; i++)
        {

            usr_signal = 0;
            sigemptyset(&(act.sa_mask));
            act.sa_flags = 0;
            sigemptyset(&mask);

            act.sa_handler = handlerusr;
            sigActionPrep(act, mask, SIGUSR1);

            while (usr_signal == 0 && first != 1)
            {
                sigsuspend(&(act.sa_mask));
            }
            sigprocmask(SIG_UNBLOCK, &mask, NULL);

            if (first == 1)
            {
                wake_miners();
            }

            sol = miner_init(obj, threads);
            msg.sol = sol;
            msg.obj = obj;
            msg.pid = getpid();
            strcpy(msg.type, "Solution");

            if (mq_send(queue, (char *)&msg, sizeof(msg), 1) == -1)
            {
                fprintf(stderr, "Error sending message\n");
                return EXIT_FAILURE;
            }
            obj = sol;

            block->coins[j] = miner->coins;
            block->miners_pid[j] = miner->pid;
        }
        strcpy(msg.type, "Finish");
        msg.sol = -1;
        msg.obj = -1;

        if (mq_send(queue, (char *)&msg, sizeof(msg), 1) == -1)
        {
            fprintf(stderr, "Error sending message\n");
            return EXIT_FAILURE;
        }

        mq_unlink(MQ_NAME);
        sem_unlink(semname);
        sem_close(sem);

        close(fdout[1]);

        munmap(miner, sizeof(Miner));
        munmap(shm_info, sizeof(Info));
        munmap(block, sizeof(Block));

        wait(NULL);

        exit(EXIT_SUCCESS);
    }
    else
    {
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}