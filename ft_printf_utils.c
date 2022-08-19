#include "ft_printf.h"

int	ft_putchar(int c)
{
	int	i;
	
	i = write(1, &c, 1);
	return(i);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		i += write(1, &*str, 1);
		str++;
	}
	return(i);
}

int ft_putnbr(int n)
{
    int a;

    a = 0;
    if (n < 0)
    {
        a += ft_putchar('-');
        n = -n;
    }
    while (n >= 10)
    {
        a += ft_putnbr(n / 10);
        n %= 10;
    }
    a += ft_putchar(n + 48);
    return (a);
}

int	ft_putnbr_u(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
	{
		i += ft_putchar(n + 48);
	}
	return(i);
}