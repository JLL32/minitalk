#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void send_char(int pid, char c)
{
    int i;

    i = 8;
    while (i--)
    {
        if (c & (1 << i))
        {
            printf("1");
            if (kill(pid, SIGUSR2) == -1) {
                printf("error occured");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            printf("0");
            if (kill(pid, SIGUSR1) == -1) {
                printf("error occured");
                exit(EXIT_FAILURE);
            }
        }
        usleep(600);
    }
}

void send_message(int pid, char *message)
{
    int i;

    printf("%d\n", *message);

    while (*message)
    {
        send_char(pid, *message);
        message++;
    }
 //   send_char(pid, '\0');
}

void handle_signal(int sig)
{
    if (sig == SIGUSR1)
        printf("Data received successfully");
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("wrong args");
        return -1;
    }
    int pid = atoi(argv[1]);
//TODO:    signal(SIGUSR1, handle_signal);
    send_message(pid, argv[2]);
    return 0;
}