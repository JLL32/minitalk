#ifndef MINITALK_H
# define MINITALK_H
# include <math.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_byte
{
	int	code;
	int	i;
}				t_byte;

void	ft_putstr(char *s);
int		ft_atoi(const char *str);
void	ft_putnbr(int n);
char	*ft_itoa(int n);
#endif
