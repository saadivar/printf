/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:45:39 by sel-biyy          #+#    #+#             */
/*   Updated: 2022/10/27 04:01:19 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			ft_putchar (s[i]);
			i++;
		}
		return (i);
	}
	return (ft_putstr("(null)"));
}

int	ft_putnbr_base(long n, char *base)
{
	long	lenbase;
	int		len_n;

	len_n = 0;
	lenbase = ft_strlen(base);
	if (n < 0)
	{
		len_n++;
		ft_putchar('-');
		n = n * (-1);
	}
	if (n >= lenbase)
	{
		len_n += ft_putnbr_base(n / lenbase, base);
		len_n += ft_putnbr_base(n % lenbase, base);
	}
	else
		len_n += ft_putchar(base[n]);
	return (len_n);
}

int	ft_put_adress(unsigned long n, char *base)
{
	unsigned long	lenbase;
	int				len_print;

	len_print = 0;
	lenbase = ft_strlen(base);
	if (n >= lenbase)
	{
		len_print += ft_put_adress(n / lenbase, base);
		len_print += ft_put_adress(n % lenbase, base);
	}
	else
		len_print += ft_putchar(base[n]);
	return (len_print);
}
