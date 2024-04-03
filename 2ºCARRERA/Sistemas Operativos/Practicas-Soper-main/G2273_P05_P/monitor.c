/*
 * File: monitor.c
 * Author: Sergio Hidalgo y Miguel Ibáñez
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <mqueue.h>
#include <string.h>
#include <semaphore.h>
#include <sys/shm.h>
#include "pow.h"

typedef struct
{
    int accept;
    int round;
    long int recived;
    long int objective;
    int flag_end;
    int sem_empty_id;
    int sem_fill_id;
    int sem_mutex_id;
    pid_t winner;
} MinerStruct;

int checker();

int checker()
{
    int fd_shm;
    MinerStruct *shm_struct = NULL;
    mqd_t queue;
    Message msg;
    struct mq_attr attributes;
    sem_t *sem_empty = NULL;
    sem_t *sem_fill = NULL;
    sem_t *sem_mutex = NULL;
    Block *actual_block = NULL;

    int i = 0;

    strcpy(msg.type, "");

    attributes.mq_maxmsg = 10;
    attributes.mq_msgsize = sizeof(Message);

    queue = mq_open(MQ_NAME,
                    O_CREAT | O_RDONLY, /* This process is only going to receive messages. */
                    S_IRUSR | S_IWUSR,  /* The user can read and write. */
                    &attributes);

    if (queue == (mqd_t)-1)
    {
        fprintf(stderr, "Error opening the queue\n");
        return EXIT_FAILURE;
    }

    if ((fd_shm = shm_open(SHM_NAME, O_RDWR | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR)) == -1)
    {
        perror("shm_open struct monitor");
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

    fd_shm = shm_open(SHM_BLOCK_NAME, O_RDWR, 0);
    while (fd_shm == -1)
    {

        fd_shm = shm_open(SHM_BLOCK_NAME, O_RDWR, 0);
    }

    actual_block = mmap(NULL, sizeof(Block), PROT_READ | PROT_WRITE, MAP_SHARED, fd_shm, 0);
    if (actual_block == NULL)
    {
        perror("Mmap");
        exit(EXIT_FAILURE);
    }
    close(fd_shm);
    i = 0;

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
        shm_struct->winner = msg.pid;

        i++;

        actual_block->id = i;
        actual_block->winner = msg.pid;
        actual_block->solution = msg.sol;
        actual_block->target = msg.obj;
        actual_block->n_votes = 1;
        actual_block->positive_votes = 1;

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
    }

    shm_struct->flag_end = 1;

    shmdt((void *)sem_fill);
    shmdt((void *)sem_empty);
    shmdt((void *)sem_mutex);

    shmctl(shm_struct->sem_empty_id, IPC_RMID, 0);
    shmctl(shm_struct->sem_fill_id, IPC_RMID, 0);
    shmctl(shm_struct->sem_mutex_id, IPC_RMID, 0);

    munmap(actual_block, sizeof(Block));
    munmap(shm_struct, sizeof(MinerStruct));

    wait(NULL);

    shm_unlink(SHM_NAME);
    exit(EXIT_SUCCESS);
}

int main()
{
    int fd_shm, i = 0;
    MinerStruct *shm_struct = NULL;
    Miner *mineraux = NULL;
    Info *info = NULL;
    sem_t *sem_empty, *sem_fill, *sem_mutex;
    pid_t pid;
    Block *block;

    fd_shm = shm_open(SHM_INFO_NAME, O_RDWR, 0);
    while (fd_shm == -1)
    {
        close(fd_shm);
        fd_shm = shm_open(SHM_INFO_NAME, O_RDWR, 0);
    }
    close(fd_shm);

    pid = fork();

    if (pid == 0)
    {
        /*Monitor*/
        fd_shm = shm_open(SHM_NAME, O_RDONLY, 0);

        /* Mapping of the memory segment. */
        shm_struct = mmap(NULL, sizeof(MinerStruct), PROT_READ, MAP_SHARED, fd_shm, 0);
        if (shm_struct == MAP_FAILED)
        {
            perror("mmap struct");
            exit(EXIT_FAILURE);
        }

        close(fd_shm);
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

        fd_shm = shm_open(SHM_INFO_NAME, O_RDWR, 0);

        info = mmap(NULL, sizeof(Info), PROT_READ | PROT_WRITE, MAP_SHARED, fd_shm, 0);
        if (info == NULL)
        {
            perror("Mmap");
            exit(EXIT_FAILURE);
        }

        close(fd_shm);

        fd_shm = shm_open(SHM_BLOCK_NAME, O_RDWR, 0);

        block = mmap(NULL, sizeof(Block), PROT_READ | PROT_WRITE, MAP_SHARED, fd_shm, 0);
        if (block == NULL)
        {
            perror("Mmap");
            exit(EXIT_FAILURE);
        }
        close(fd_shm);

        /*the loop will only stops when flag_end equals to 1*/

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
                fflush(stdout);
                printf("\nId:       %.4d\nWinner:   %d\nTarget:   %.8ld\nSolution: %.8ld (validated)\nVotes     %d/%d\nWallets:   ", block->id, shm_struct->winner, shm_struct->objective, shm_struct->recived, block->positive_votes, block->n_votes);

                i = 0;
                while (info->pid_active_miners[i] != -1 && info->miners_shr_ids[i][0] != '\0')
                {
                    fd_shm = shm_open(info->miners_shr_ids[i], O_RDWR, 0);

                    if (fd_shm < 0)
                    {
                        perror("shm_open miner on monitor");
                        exit(EXIT_FAILURE);
                    }

                    /* Mapping of the memory segment. */
                    mineraux = mmap(NULL, sizeof(Miner), PROT_READ | PROT_WRITE, MAP_SHARED, fd_shm, 0);
                    if (mineraux == MAP_FAILED)
                    {
                        perror("mmap struct");
                        exit(EXIT_FAILURE);
                    }

                    close(fd_shm);
                    if (mineraux->pid == block->winner)
                    {
                        mineraux->coins++;
                    }

                    if (mineraux->pid == block->winner)
                    {
                        printf("%d:%.2d  ", block->miners_pid[i], block->coins[i] +1);
                    }
                    else
                    {
                        printf("%d:%.2d  ", block->miners_pid[i], block->coins[i] );
                    }
                    

                    i++;
                    munmap(mineraux, sizeof(Miner));
                }
                printf("\n");
            }
            else
            {
                fflush(stdout);

                printf("\nId:       %.4d\nWinner:   %d\nTarget:   %.8ld\nSolution: %.8ld (rejected)\nVotes     %d/%d\nWallets:   ", block->id, shm_struct->winner, shm_struct->objective, shm_struct->recived, block->positive_votes, block->n_votes);
                i = 0;
                while (info->pid_active_miners[i] != -1 && info->miners_shr_ids[i][0] != '\0')
                {
                    fd_shm = shm_open(info->miners_shr_ids[i], O_RDONLY, 0);
                    if (fd_shm < 0)
                    {
                        perror("shm_open miner struct on monitor");
                        exit(EXIT_FAILURE);
                    }

                    /* Mapping of the memory segment. */
                    mineraux = mmap(NULL, sizeof(Miner), PROT_READ, MAP_SHARED, fd_shm, 0);
                    if (mineraux == MAP_FAILED)
                    {
                        perror("mmap struct");
                        exit(EXIT_FAILURE);
                    }

                    close(fd_shm);
                    printf("%d:%.2d  ", mineraux->pid, mineraux->coins);

                    i++;
                    munmap(mineraux, sizeof(Miner));
                }

                printf("\n");
            }
            sem_post(sem_mutex);
            sem_post(sem_empty);
        }

        printf("\n");

        shmdt((void *)sem_fill);
        shmdt((void *)sem_empty);
        shmdt((void *)sem_mutex);

        munmap(info, sizeof(Info));
        munmap(block, sizeof(Block));
        munmap(shm_struct, sizeof(MinerStruct));

        exit(EXIT_SUCCESS);
    }
    else if (pid > 0)
    {

        if (checker() == -1)
        {
            exit(EXIT_SUCCESS);
        }
    }
    else
    {
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}