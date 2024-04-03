#define _POSIX_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

/* Handler function for the signal SIGINT. */
void handler(int sig)
{
    printf("Signal number %d received\n", sig);
    fflush(stdout);
}

int main(void)
{
    struct sigaction act;

    act.sa_handler = handler;
    sigemptyset(&(act.sa_mask));
    act.sa_flags = 0;

    if (sigaction(SIGHUP, &act, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    if (sigaction(SIGINT, &act, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }


    if (sigaction(SIGQUIT, &act, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    if (sigaction(SIGILL, &act, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    if (sigaction(SIGTRAP, &act, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }


    if (sigaction(SIGABRT, &act, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }


    if (sigaction(SIGFPE, &act, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }


    if (sigaction(SIGBUS, &act, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }


    if (sigaction(SIGSEGV, &act, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }


    if (sigaction(SIGSYS, &act, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }


    if (sigaction(SIGPIPE, &act, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }



    if (sigaction(SIGALRM, &act, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }


    if (sigaction(SIGTERM, &act, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }


    if (sigaction(SIGURG, &act, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }


    if (sigaction(SIGTSTP, &act, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }


    if (sigaction(SIGCONT, &act, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }


    if (sigaction(SIGCHLD, &act, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }


    if (sigaction(SIGTTIN, &act, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }


    if (sigaction(SIGTTOU, &act, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }


    if (sigaction(SIGPOLL, &act, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }


    if (sigaction(SIGXCPU, &act, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }


    if (sigaction(SIGXFSZ, &act, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }


    if (sigaction(SIGVTALRM, &act, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }


    if (sigaction(SIGPROF, &act, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    if (sigaction(SIGUSR1, &act, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }


    if (sigaction(SIGUSR2, &act, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }


    if (sigaction(SIGWINCH, &act, NULL) < 0)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    
    while (1)
    {
        printf("Waiting Ctrl+C (PID = %d)\n", getpid());
        sleep(9999);
    }
}
