#include "minitalk.h"

void	send_char(int pid, char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (c & (1 << i))
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putstr("error occured");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putstr("error occured");
				exit(EXIT_FAILURE);
			}
		}
		usleep(600);
	}
}

void	send_message(int pid, char *message)
{
	while (*message)
	{
		send_char(pid, *message);
		message++;
	}
	send_char(pid, '\0');
}

void	handle_signal(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr("Data received successfully");
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_putstr("Wrong args");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid == -10)
		exit(EXIT_FAILURE);
	send_message(pid, argv[2]);
	return (0);
}
