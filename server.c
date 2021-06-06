#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void handler(int signum)
{
    if (signum == SIGUSR1)
    {
        printf("Received SIGUSR1!\n");
    }
}

void handler2(int signum)
{
    if (signum == SIGUSR2)
    {
        printf("Received SIGUSR2!\n");
    }
}

int main(int argc, char **argv)
{
    signal(SIGUSR2, handler2);
    signal(SIGUSR1, handler);
    int pid = getpid();
    printf("%d\n", pid);
    while (1 == 1)
    {
    }
    return 0;
}