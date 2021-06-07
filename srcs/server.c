#include "minitalk.h"

int byte = 0;
int i = 8;

void print_pid()
{
    char *pid;

    pid = ft_itoa(getpid());
    ft_putstr("Server's id: ");
    ft_putstr(pid);
    write(1, "\n", 1);
    free(pid);
}

void handler_sig1(int signum)
{
    if (signum == SIGUSR1)
        i--;
}

void handler_sig2(int signum)
{
    if (signum == SIGUSR2)
    {
        byte += pow(2, i);
        i--;
    }
}

int main(void)
{
    char c;

    signal(SIGUSR2, handler_sig2);
    signal(SIGUSR1, handler_sig1);

    print_pid();
    while (true)
    {
        if (i == 0)
        {
            c = byte / 2;
            write(1, &c, 1);
            if (c == '\0')
            {
                write(1, "\n", 1);
            }
            i = 8;
            byte = 0;
        }
    }
    return 0;
}