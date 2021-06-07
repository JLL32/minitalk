# ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <math.h>

typedef struct  s_byte {
    int code;
    int i;
}               t_byte;

void	ft_putstr(char *s);
int		ft_atoi(const char *str);
void	ft_putnbr(int n);
#endif