#define _POSIX_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>

#define DATANAME "voting_data.dat"
#define VOTENAME "voting_votes.dat"
#define SEM_NAME "/wsew1m2"
#define SEM_NAME2 "/sewm1ws21"

static volatile sig_atomic_t usr_signal = 0;
static volatile sig_atomic_t reset_signal = 0;

int voter(int n_procs, pid_t pid, sem_t *sem, sem_t *sem2);
int candidate(int n_procs, pid_t pid, sem_t *sem, sem_t *sem2);
void handlerusr(int sig);
int randomProc(int n);
int sigActionPrep(struct sigaction act, sigset_t mask, int sig);
void sem_print(sem_t *sem);
void handlereset(int sig);
void milisleep(int tms);

void milisleep(int milliseconds)
{
    struct timeval time_v;
    time_v.tv_sec = milliseconds / 1000;
    time_v.tv_usec = (milliseconds % 1000) * 1000;
    select(0, NULL, NULL, NULL, &time_v);
}

void sem_print(sem_t *sem)
{
    int sval;
    if (sem_getvalue(sem, &sval) == -1)
    {
        perror("sem_getvalue");
        sem_unlink(SEM_NAME);
        exit(EXIT_FAILURE);
    }
    printf("Semaphore value: %d pid = %d\n", sval, getpid());
    fflush(stdout);
}

int sigActionPrep(struct sigaction act, sigset_t mask, int sig)
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

int candidate(int n_procs, pid_t pid, sem_t *sem, sem_t *sem2)
{
    FILE *f;
    int i = 0, yes = 0, no = 0, counter = 0;
    char aux[120];
    pid_t pid2 = -1;

    f = fopen(VOTENAME, "w");
    if (f == NULL)
    {
        perror("file");
        exit(EXIT_FAILURE);
    }
    fclose(f);

    f = fopen(DATANAME, "r");
    if (f == NULL)
    {
        perror("file");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n_procs; i++)
    {
        if (fgets(aux, 120, f) != NULL)
        {
            pid2 = atoi(aux);
            if (kill(pid2, SIGUSR2) == -1)
            {
                perror("signal to voters");
                exit(EXIT_FAILURE);
            }
        }
    }
    fclose(f);
    sem_post(sem);

    sem_wait(sem2);
    f = fopen(DATANAME, "r");
    if (f == NULL)
    {
        perror("file");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n_procs; i++)
    {
        if (fgets(aux, 120, f) != NULL)
        {
            pid2 = atoi(aux);
            if (pid2 == getpid())
            {
            }
            else if (kill(pid2, SIGUSR1) == -1)
            {
                perror("signal to voters");
                exit(EXIT_FAILURE);
            }
        }
    }
    fclose(f);

    while (1)
    {
        sem_wait(sem2);
        counter++;
        f = fopen(VOTENAME, "a");
        if (f == NULL)
        {
            perror("file");
            exit(EXIT_FAILURE);
        }
        fclose(f);
        if (counter == n_procs - 1)
        {
            sem_wait(sem);
            f = fopen(VOTENAME, "a");
            if (f == NULL)
            {
                perror("file");
                exit(EXIT_FAILURE);
            }

            if (randomProc(2) == 0)
            {
                fprintf(f, "Y\n");
            }
            else
            {
                fprintf(f, "N\n");
            }

            fclose(f);

            sem_post(sem);

            break;
        }
    }

    printf("Candidate %d => [ ", getpid());

    f = fopen(VOTENAME, "r");
    if (f == NULL)
    {
        perror("file");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n_procs; i++)
    {
        if (fgets(aux, 120, f) != NULL)
        {
            if (aux[0] == 'Y')
            {
                printf("Y ");
                yes++;
            }
            else
            {
                printf("N ");
                no++;
            }
        }
    }
    fclose(f);

    printf("] => ");
    if (yes > no)
    {
        printf("Acepted\n");
    }
    else
    {

        printf("Rejected\n");
    }
    fflush(stdout);

    milisleep(250);
}

int randomProc(int n)
{
    if (n <= 0)
    {
        return -1;
    }

    return (rand() % n);
}

void handlerusr(int sig)
{
    usr_signal = 1;
}

void handlereset(int sig)
{
    reset_signal = 1;
}

int voter(int n_procs, pid_t pid, sem_t *sem, sem_t *sem2)
{
    FILE *f;
    int i, val = 0;
    char aux[120];
    struct sigaction act, act_r;
    sigset_t mask;
    pid_t pid2;

    usr_signal = 0;
    sigemptyset(&(act.sa_mask));
    sigemptyset(&mask);

    act.sa_handler = handlerusr;
    sigActionPrep(act, mask, SIGUSR1);

    while (usr_signal == 0)
    {
        sigsuspend(&(act.sa_mask));
    }
    sigprocmask(SIG_UNBLOCK, &mask, NULL);

    act_r.sa_handler = handlereset;
    sigemptyset(&(act_r.sa_mask));

    if (sigaction(SIGINT, &act_r, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    while (reset_signal == 0)
    {

        usr_signal = 0;

        act.sa_handler = handlerusr;
        sigemptyset(&(act.sa_mask));
        if (sigaction(SIGUSR2, &act, NULL) < 0)
        {
            perror("sigaction");
            exit(EXIT_FAILURE);
        }

        if (sem_wait(sem) == -1)
        {
            
            sem_wait(sem);
        }

        if (usr_signal == 0)
        {

            candidate(n_procs, pid, sem, sem2);
        }
        else if (usr_signal == 1)
        {

            sem_print(sem);
            sem_post(sem);
            usr_signal = 0;

            act.sa_handler = handlerusr;
            sigActionPrep(act, mask, SIGUSR1);

            while (usr_signal == 0)
            {
                sigsuspend(&(act.sa_mask));
            }
            sigprocmask(SIG_UNBLOCK, &mask, NULL);
            usr_signal = 0;

            if (sem_wait(sem) == -1)
            {
                sem_wait(sem);
            }

            f = fopen(VOTENAME, "a");
            if (f == NULL)
            {
                perror("file");
                exit(EXIT_FAILURE);
            }

            if (randomProc(2) == 0)
            {
                fprintf(f, "Y\n");
            }
            else
            {
                fprintf(f, "N\n");
            }

            fclose(f);
            sem_post(sem);
            sem_post(sem2);

            milisleep(1);
        }
    }

    sem_close(sem);
    sem_close(sem2);
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
    int n_procs = 0, n_secs = 0, i = 0;
    FILE *f;
    pid_t pid;
    char aux[120];
    struct sigaction act;
    sigset_t mask;
    sem_t *sem = NULL, *sem2 = NULL;

    if (argc != 3)
    {
        printf("Wrong parameters, try ./voting <N_PROCS> <N_SECS>\n");
    }

    n_procs = atoi(argv[1]);
    n_secs = atoi(argv[2]);

    f = fopen(DATANAME, "w");
    if (f == NULL)
    {
        perror("file");
        exit(EXIT_FAILURE);
    }
    fclose(f);

    f = fopen(VOTENAME, "w");
    if (f == NULL)
    {
        perror("file");
        exit(EXIT_FAILURE);
    }
    fclose(f);

    if ((sem = sem_open(SEM_NAME, O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 1)) == SEM_FAILED)
    {
        perror("sem_open");
        exit(EXIT_FAILURE);
    }
    sem_unlink(SEM_NAME);

    if ((sem2 = sem_open(SEM_NAME2, O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 0)) == SEM_FAILED)
    {
        perror("sem_open");
        exit(EXIT_FAILURE);
    }
    sem_unlink(SEM_NAME2);

    /*Loop to create the diferent processes*/
    for (i = 0; i < n_procs; i++)
    {
        sleep(1);

        pid = fork();

        if (pid < 0)
        {
            perror("fork");
            fclose(f);
            exit(EXIT_FAILURE);
        }

        if (pid == 0)
        {
            srand(time(NULL));
            /*If it is the child it goes to the voter function*/
            voter(n_procs, pid, sem, sem2);
        }
        else
        {
            /*If it is the main (the father) it will print the pid on a file*/
            f = fopen(DATANAME, "a");
            if (f == NULL)
            {
                perror("file");
                exit(EXIT_FAILURE);
            }
            fprintf(f, "%d\n", pid);
            fclose(f);
        }
    }
    sem_close(sem);

    f = fopen(DATANAME, "r");
    if (f == NULL)
    {
        perror("file");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n_procs; i++)
    {
        if (fgets(aux, 120, f) != NULL)
        {
            pid = atoi(aux);
            if (kill(pid, SIGUSR1) == -1)
            {
                fclose(f);
                perror("signal to voters");
                exit(EXIT_FAILURE);
            }
        }
    }

    fclose(f);

    sigemptyset(&(act.sa_mask));
    sigemptyset(&mask);
    act.sa_handler = handlerusr;
    sigActionPrep(act, mask, SIGINT);

    while (usr_signal == 0)
    {
        sigsuspend(&(act.sa_mask));
    }
    sigprocmask(SIG_UNBLOCK, &mask, NULL);

    f = fopen(DATANAME, "r");
    if (f == NULL)
    {
        perror("file");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n_procs; i++)
    {
        if (fgets(aux, 120, f) != NULL)
        {
            pid = atoi(aux);

            if (kill(pid, SIGINT) == -1)
            {
                perror("signal to voters");
                exit(EXIT_FAILURE);
            }

            wait(NULL);
        }
    }
    fclose(f);

    printf("Finishing by signal\n");
    sem_close(sem);
    sem_close(sem2);

    exit(EXIT_SUCCESS);
}
