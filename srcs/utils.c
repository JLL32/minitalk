#include "minitalk.h"

void	ft_putstr(char *s)
{
	int i;

	if (!s)
		return ;
	i = 0;
	while (*(s + i) != '\0')
	{
		write(1, (s + i), 1);
		i++;
	}
}

int		ft_atoi(const char *str)
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

static int		ft_count(int n)
{
	unsigned int	nbr;
	int				i;

	i = 1;
	if (n < 0)
	{
		nbr = -n;
		i++;
	}
	else
		nbr = n;
	while (nbr / 10 > 0)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	unsigned int	nbr;
	char			*s;
	int				count;

	count = ft_count(n);
	if (!(s = (char *)malloc(count + 1)))
		return (0);
	if (n == 0)
		*s = '0';
	if (n < 0)
	{
		s[0] = '-';
		nbr = -n;
	}
	else
		nbr = n;
	s[count--] = '\0';
	while (nbr > 0)
	{
		if (count == 0 && n < 0)
			break ;
		*(s + count--) = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (s);
}