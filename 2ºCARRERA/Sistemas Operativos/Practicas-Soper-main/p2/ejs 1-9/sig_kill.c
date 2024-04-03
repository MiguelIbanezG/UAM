#define _POSIX_SOURCE
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>


int main(int argc, char *argv[]) {
    int sig;
    pid_t pid;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s -<signal> <pid>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sig = atoi(argv[1] + 1);
    pid = (pid_t)atoi(argv[2]);


    if (kill(pid, sig) == -1)
    {
        perror("kill");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
