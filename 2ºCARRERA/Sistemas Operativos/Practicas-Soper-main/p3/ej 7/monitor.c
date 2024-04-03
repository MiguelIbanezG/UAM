/*
 * File: monitor.c
 * Author: Sergio Hidalgo y Miguel Ibáñez
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <mqueue.h>
#include <string.h>
#include <semaphore.h>
#include <sys/shm.h>
#include "pow.h"

#define SHM_NAME "/shm_first"

typedef struct
{
    int accept;
    long int recived;
    long int objective;
    int flag_end;
    int sem_empty_id;
    int sem_fill_id;
    int sem_mutex_id;
} MinerStruct;

int checker(int lag);

int checker(int lag)
{
    int fd_shm;
    MinerStruct *shm_struct = NULL;
    mqd_t queue;
    Message msg;
    struct mq_attr attributes;
    sem_t *sem_empty = NULL;
    sem_t *sem_fill = NULL;
    sem_t *sem_mutex = NULL;

    if (lag < 0)
    {
        return -1;
    }

    strcpy(msg.type, "");

    attributes.mq_maxmsg = 10;
    attributes.mq_msgsize = sizeof(Message);

    queue = mq_open(MQ_NAME,
                    O_CREAT | O_RDONLY, /* This process is only going to receive messages. */
                    S_IRUSR | S_IWUSR,                  /* The user can read and write. */
                    &attributes);

    if (queue == (mqd_t)-1)
    {
        fprintf(stderr, "Error opening the queue\n");
        return EXIT_FAILURE;
    }

    if ((fd_shm = shm_open(SHM_NAME, O_RDWR | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR)) == -1)
    {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    /* Resize of the memory segment. */
    if (ftruncate(fd_shm, sizeof(MinerStruct)) == -1)
    {
        perror("ftruncate");
        shm_unlink(SHM_NAME);
        exit(EXIT_FAILURE);
    }

    /* Mapping of the memory segment. */
    shm_struct = mmap(NULL, sizeof(MinerStruct), PROT_READ | PROT_WRITE, MAP_SHARED, fd_shm, 0);

    close(fd_shm);
    if (shm_struct == MAP_FAILED)
    {
        perror("mmap");
        shm_unlink(SHM_NAME);
        exit(EXIT_FAILURE);
    }
    shm_struct->flag_end = 0;

    shm_struct->sem_empty_id = shmget(IPC_PRIVATE, sizeof(sem_t), IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
    if (shm_struct->sem_empty_id < 0)
    {
        perror("Create shared sem");
        shm_unlink(SHM_NAME);
        exit(EXIT_FAILURE);
    }

    shm_struct->sem_fill_id = shmget(IPC_PRIVATE, sizeof(sem_t), IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
    if (shm_struct->sem_fill_id < 0)
    {
        perror("Create shared sem");
        shm_unlink(SHM_NAME);
        exit(EXIT_FAILURE);
    }

    shm_struct->sem_mutex_id = shmget(IPC_PRIVATE, sizeof(sem_t), IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
    if (shm_struct->sem_mutex_id < 0)
    {
        perror("Create shared sem");
        shm_unlink(SHM_NAME);
        exit(EXIT_FAILURE);
    }

    sem_empty = (sem_t *)shmat(shm_struct->sem_empty_id, NULL, 0);
    if (sem_empty == NULL)
    {
        perror("Attach shared sem");
        shm_unlink(SHM_NAME);
        exit(EXIT_FAILURE);
    }

    sem_fill = (sem_t *)shmat(shm_struct->sem_fill_id, NULL, 0);
    if (sem_fill == NULL)
    {
        perror("Attach shared sem");
        shmdt((void *)sem_empty);
        shm_unlink(SHM_NAME);
        exit(EXIT_FAILURE);
    }

    sem_mutex = (sem_t *)shmat(shm_struct->sem_mutex_id, NULL, 0);
    if (sem_mutex == NULL)
    {
        perror("Attach shared sem");
        shmdt((void *)sem_fill);
        shmdt((void *)sem_empty);
        shm_unlink(SHM_NAME);
        exit(EXIT_FAILURE);
    }

    if (sem_init(sem_empty, 1, 1) < 0)
    {
        perror("sem_init");
        shm_unlink(SHM_NAME);
        shmdt((void *)sem_fill);
        shmdt((void *)sem_empty);
        shmdt((void *)sem_mutex);
        exit(EXIT_FAILURE);
    }

    if (sem_init(sem_fill, 1, 0) < 0)
    {
        perror("sem_init");
        shm_unlink(SHM_NAME);
        shmdt((void *)sem_fill);
        shmdt((void *)sem_empty);
        shmdt((void *)sem_mutex);
        exit(EXIT_FAILURE);
    }

    if (sem_init(sem_mutex, 1, 1) < 0)
    {

        perror("sem_init");
        shmdt((void *)sem_fill);
        shmdt((void *)sem_empty);
        shmdt((void *)sem_mutex);
        shm_unlink(SHM_NAME);
        exit(EXIT_FAILURE);
    }

    printf("[%d] Checking blocks...\n", getpid());

    while (strcmp(msg.type, "Finish") != 0)
    {
        sem_wait(sem_empty);
        sem_wait(sem_mutex);
        if (mq_receive(queue, (char *)&msg, sizeof(msg), NULL) == -1)
        {
            fprintf(stderr, "Error receiving message\n");
            return EXIT_FAILURE;
        }

        shm_struct->recived = msg.sol;
        shm_struct->objective = msg.obj;

        if (msg.obj < 0 || msg.sol < 0)
        {
            sem_post(sem_mutex);
        sem_post(sem_fill);
            break;
        }

        if (pow_hash(msg.sol) == msg.obj)
        {
            shm_struct->accept = 1;
        }
        else
        {
            shm_struct->accept = 0;
        }
        

        sem_post(sem_mutex);
        sem_post(sem_fill);

        usleep(lag * 1000);
    }
    printf("[%d] Finishing\n", getpid());

    shm_struct->flag_end = 1;

    shmdt((void *)sem_fill);
    shmdt((void *)sem_empty);
    shmdt((void *)sem_mutex);

    shmctl(shm_struct->sem_empty_id, IPC_RMID, 0);
    shmctl(shm_struct->sem_fill_id, IPC_RMID, 0);
    shmctl(shm_struct->sem_mutex_id, IPC_RMID, 0);

    munmap(shm_struct, sizeof(MinerStruct));

    shm_unlink(SHM_NAME);
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
    int lag = 0, fd_shm;
    MinerStruct *shm_struct = NULL;
    sem_t *sem_empty, *sem_fill, *sem_mutex;

    if (argc != 2)
    {
        shm_unlink(SHM_NAME);

        printf("Parameters doesn't match ./monitor <LAG>\n");
        exit(EXIT_FAILURE);
    }

    lag = atoi(argv[1]);

    if ((fd_shm = shm_open(SHM_NAME, O_RDONLY, 0)) == -1)
    {
        if (checker(lag) == -1)
        {
            exit(EXIT_SUCCESS);
        }
    }
    else
    {
        /*Monitor*/

        /*Opens the shared memory*/
        if ((fd_shm = shm_open(SHM_NAME, O_RDONLY, 0)) == -1)
        {
            perror("shm_open");
            exit(EXIT_FAILURE);
        }

        /* Mapping of the memory segment. */
        shm_struct = mmap(NULL, sizeof(MinerStruct), PROT_READ, MAP_SHARED, fd_shm, 0);
        close(fd_shm);
        if (shm_struct == MAP_FAILED)
        {
            perror("mmap");
            exit(EXIT_FAILURE);
        }

        /*Attaches the semaphores to the shared segment*/
        sem_empty = (sem_t *)shmat(shm_struct->sem_empty_id, NULL, 0);
        if (sem_empty == NULL)
        {
            perror("Attach shared sem");
            shm_unlink(SHM_NAME);
            exit(EXIT_FAILURE);
        }

        sem_fill = (sem_t *)shmat(shm_struct->sem_fill_id, NULL, 0);
        if (sem_fill == NULL)
        {
            perror("Attach shared sem");
            shmdt((void *)sem_empty);
            shm_unlink(SHM_NAME);
            exit(EXIT_FAILURE);
        }

        sem_mutex = (sem_t *)shmat(shm_struct->sem_mutex_id, NULL, 0);
        if (sem_mutex == NULL)
        {
            perror("Attach shared sem");
            shmdt((void *)sem_fill);
            shmdt((void *)sem_empty);
            shm_unlink(SHM_NAME);
            exit(EXIT_FAILURE);
        }

        /*the loop will only stops when flag_end equals to 1*/
        printf("[%d] Printing blocks...\n", getpid());

        while (shm_struct->flag_end != 1)
        {
            sem_wait(sem_fill);
            sem_wait(sem_mutex);

            /*if the checker has ended*/
            if (shm_struct->objective < 0 || shm_struct->recived < 0)
            {
                sem_post(sem_mutex);
                sem_post(sem_empty);
                break;
            }

            if (shm_struct->accept == 1)
            {
                printf("Solution accepted: %08ld -->%08ld\n", shm_struct->objective, shm_struct->recived);
            }
            else
            {
                printf("Solution rejected: %08ld !->%08ld\n", shm_struct->objective, shm_struct->recived);
            }
            sem_post(sem_mutex);
            sem_post(sem_empty);
            usleep(lag * 1000);
        }

        printf("[%d] Finishing\n", getpid());

        shmdt((void *)sem_fill);
        shmdt((void *)sem_empty);
        shmdt((void *)sem_mutex);

        munmap(shm_struct, sizeof(MinerStruct));

        exit(EXIT_SUCCESS);
    }
    
    exit(EXIT_SUCCESS);
}   