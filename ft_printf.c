#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

#include <stdio.h>
#include <string.h>
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

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i += ft_putchar('-');
		i += ft_putchar('2');
		i += ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		i += ft_putchar('-');
		n *= -1;
		i += ft_putnbr(n);
	}
	else if (n > 9)
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

int	hexdecimal_l(int n)
{
	int	i;

	i = 0;
	if (n > 16)
	{
		i += hexdecimal_l(n / 16);
		i += hexdecimal_l(n % 16);
	}
	else
	{
		if (n < 10)
			i += ft_putchar(n + 48);
		else
			i += ft_putchar(n + 87);
	}
	return (i);
}

int	hexdecimal_u(int n)
{
	int	i;

	i = 0;
	if (n > 16)
	{
		i += hexdecimal_u(n / 16);
		i += hexdecimal_u(n % 16);
	}
	else
	{
		if (n < 10)
			i += ft_putchar(n + 48);
		else
			i += ft_putchar(n + 55);
	}
	return (i);
}

int	printf_pointer(int p)
{
	int	i;

	i = 0;
	i += ft_putstr("0x");
	i += hexdecimal_l(p);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int a;
	va_list args;
	va_start(args, format);

	a = 0;
	while(*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd')
				a += ft_putnbr(va_arg(args, int));
			else if (*format == 's')
				a += ft_putstr(va_arg(args, char*));
			else if (*format == 'c')
				a += ft_putchar(va_arg(args, int));
			else if (*format == '%')
				a += ft_putchar(37);
			else if (*format == 'i')
				a += ft_putnbr(va_arg(args, int));
			else if (*format == 'u')
			{
				int u = va_arg(args, unsigned int);
				if (u < 0)
					a += ft_putnbr_u(4294967296 + u);
				else
					a += ft_putnbr(u);
			}
			else if (*format == 'x')
				a += hexdecimal_l(va_arg(args, unsigned int));
			else if (*format == 'X')
				a += hexdecimal_u(va_arg(args, unsigned int));
			else if (*format == 'p')
				a += printf_pointer(va_arg(args, unsigned long long));
			format++;
		}
		a += write(1, format, 1);
		format++;
	}
	va_end(args);
	return(a);
}

int main(void)
{
	int	return_of_my_printf;
	int	return_of_printf;
	int	a = 1223232;


	return_of_my_printf = ft_printf("0 try this %d && %s && %c && %% && %u && %x && %X && %p\n", -12, "hello world", 'c', -10, a, a, a);
    return_of_printf = printf("1 try this %d && %s && %c && %% && %u && %x && %X && %p\n", -12, "hello world", 'c', -10, a, a, a);
	printf("the return value of my printf = [%d]\n", return_of_my_printf);
	printf("the return value of printf = [%d]\n", return_of_printf);
	printf("try %%p = [%p]\n", a);
	printf("try %%X = [%X]\n", a);
	printf("try %%x = [%x]\n", a);
}