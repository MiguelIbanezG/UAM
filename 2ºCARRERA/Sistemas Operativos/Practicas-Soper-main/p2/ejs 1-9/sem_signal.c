#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define SEM_NAME "/example_seqqm"

void handler(int sig) {
    printf("2\n");

    return;
}

int main(void) {
	sem_t *sem = NULL;
    struct sigaction act;

	if ((sem = sem_open(SEM_NAME, O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 0)) == SEM_FAILED) {
		perror("sem_open");
		exit(EXIT_FAILURE);
	}
	sem_unlink(SEM_NAME);

    sigemptyset(&(act.sa_mask));
    act.sa_flags = 0;

    /* The handler for SIGINT is set. */
    act.sa_handler = handler;
    if (sigaction(SIGINT, &act, NULL) < 0) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

	printf("Starting wait (PID=%d)\n", getpid());
	

    if (sem_wait (sem) == -1)
    {
        sem_wait(sem);
    }
    


    printf("Finishing wait\n");
}