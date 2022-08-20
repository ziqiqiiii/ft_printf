/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:15:04 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/08/20 16:43:56 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexdecimal_l(unsigned long long n)
{
	int	i;

	i = 0;
	if (n >= 16)
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

int	hexdecimal_u(unsigned long long n)
{
	int	i;

	i = 0;
	if (n >= 16)
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

int	printf_pointer(unsigned long long p)
{
	int	i;

	i = 0;
	i += ft_putstr("0x");
	i += hexdecimal_l(p);
	return (i);
}

int	printf_specifiers(va_list args, char format, int a)
{
	if (format == 'd')
		a += ft_putnbr(va_arg(args, int));
	else if (format == 's')
		a += ft_putstr(va_arg(args, char *));
	else if (format == 'c')
		a += ft_putchar(va_arg(args, int));
	else if (format == '%')
		a += ft_putchar(37);
	else if (format == 'i')
		a += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		a += ft_putnbr_u(va_arg(args, unsigned int));
	else if (format == 'x')
		a += hexdecimal_l(va_arg(args, unsigned int));
	else if (format == 'X')
		a += hexdecimal_u(va_arg(args, unsigned int));
	else if (format == 'p')
		a += printf_pointer(va_arg(args, unsigned long long));
	return (a);
}

int	ft_printf(const char *format, ...)
{
	int		a;
	va_list	args;

	va_start(args, format);
	a = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			a = printf_specifiers(args, *format, a);
		}
		else
			a += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (a);
}
