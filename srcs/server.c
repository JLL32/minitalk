#include "minitalk.h"

t_byte	g_byte = {0, 7};

void	print_pid(void)
{
	ft_putstr("Server's id: ");
	ft_putnbr(getpid());
	write(1, "\n", 1);
}

void	handler_sig1(int signum)
{
	if (signum == SIGUSR1)
		g_byte.i--;
}

void	handler_sig2(int signum)
{
	if (signum == SIGUSR2)
		g_byte.code |= 0b1 << g_byte.i;
	g_byte.i--;
}

int	main(void)
{
	int		c;

	signal(SIGUSR2, handler_sig2);
	signal(SIGUSR1, handler_sig1);
	print_pid();
	while (true)
	{
		if (g_byte.i == -1)
		{
			c = g_byte.code;
			write(1, &c, 1);
			g_byte.i = 7;
			g_byte.code = 0;
		}
	}
	return (0);
}
