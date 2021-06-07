#include "minitalk.h"

void	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (*(s + i) != '\0')
	{
		write(1, (s + i), 1);
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int				j;
	unsigned long	res;
	int				temp;

	temp = 1;
	j = 0;
	res = 0;
	while (*str > 0 && *str <= 32)
	{
		if (*str == 27)
			return (0);
		str++;
	}
	if (*str == '-')
	{
		temp = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*(str + j) >= 48 && *(str + j) <= 57)
		res = res * 10 + *(str + j++) - '0';
	return (res * temp);
}

void	ft_putnbr(int n)
{
	unsigned int	nbr;
	char			i;

	if (n < 0)
	{
		write(1, "-", 1);
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		i = nbr % 10 + '0';
		write(1, &i, 1);
	}
	else
	{
		i = nbr + '0';
		write(1, &i, 1);
	}
}
