/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:16:53 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/08/20 16:18:33 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		i += ft_putstr("(null)");
		return (i);
	}
	while (*str != '\0')
	{
		i += ft_putchar(*str);
		str++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	a;

	a = 0;
	if (n == -2147483648)
	{
		a += ft_putchar('-');
		a += ft_putchar('2');
		n = 147483648;
	}
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
	return (i);
}
