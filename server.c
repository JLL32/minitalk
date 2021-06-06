#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>

int byte = 0;
int i = 8;

void handler(int signum)
{
    if (signum == SIGUSR1)
    {
        i--;
    }
}

void handler2(int signum)
{
    if (signum == SIGUSR2)
    {
        byte += pow(2, i);
        i--;
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
        if (i == 0)
        {
            char c = byte / 2;
            write(1, &c, 1);
            i = 8;
            if (c == '\0') {
                write(1, "\n", 1);
            }
            byte = 0;
        }
    }
    return 0;
}