#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_putnbr_u(unsigned int n);
int	hexdecimal_l(int n);
int	hexdecimal_u(int n);
int	printf_pointer(int p);
int	ft_printf(const char *format, ...);

#endif
