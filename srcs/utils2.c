#include "minitalk.h"

static int	ft_count(int n)
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

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	char			*s;
	int				count;

	count = ft_count(n);
	s = (char *) malloc(count + 1);
	if (!s)
		return (0);
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

int	ft_pow(int base, int exponent)
{
	int	result;

	result = 1;
	while (exponent--)
		result = result * base;
	return (result);
}
