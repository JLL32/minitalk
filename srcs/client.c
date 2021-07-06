#include "minitalk.h"
#include "stdlib.h"

void	send_char(int server_pid, char c, char *client_pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (c & (1 << i))
		{
			if (kill(server_pid, SIGUSR2) == -1)
			{
				ft_putstr("error occured");
				free(client_pid);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(server_pid, SIGUSR1) == -1)
			{
				ft_putstr("error occured");
				free(client_pid);
				exit(EXIT_FAILURE);
			}
		}
		usleep(100);
	}
}

void	send_message(int server_pid, char *message, char *client_pid)
{
	while (*message)
	{
		send_char(server_pid, *message, client_pid);
		message++;
	}
}

static void	is_id(char *str)
{
	if (*str == '0')
	{
		ft_putstr("The pid format is incorrect!");
		exit(EXIT_FAILURE);
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			ft_putstr("The pid format is incorrect!");
			exit(EXIT_FAILURE);
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*client_pid;

	if (argc != 3)
	{
		ft_putstr("Wrong args");
		exit(EXIT_FAILURE);
	}
	is_id(argv[1]);
	server_pid = ft_atoi(argv[1]);
	client_pid = ft_itoa((int) getpid());
	send_message(server_pid, client_pid, client_pid);
	free(client_pid);
	send_message(server_pid, ": ", client_pid);
	send_message(server_pid, argv[2], client_pid);
	send_message(server_pid, "\n", client_pid);
	ft_putstr("Message Received");
	return (0);
}
