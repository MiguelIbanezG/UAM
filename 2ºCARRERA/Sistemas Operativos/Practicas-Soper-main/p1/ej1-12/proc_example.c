#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NUM_PROC 10

int main(void) {
	int i;
	pid_t pid, ppid;

	for (i = 0; i < NUM_PROC; i++) {
		pid = fork();
		wait(NULL);
		if (pid <  0) {
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0) {

			pid = fork();
			sleep(2);

			ppid = getppid();
			pid = getpid();
			printf("Child PID=%d, Parent PID=%d\n", pid, ppid );
			exit(EXIT_SUCCESS);
		}
		else if (pid > 0) {
			printf("Parent %d\n", i);
		}
	}
	wait(NULL);
	exit(EXIT_SUCCESS);
}