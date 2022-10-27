/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 23:59:21 by sel-biyy          #+#    #+#             */
/*   Updated: 2022/10/27 04:05:56 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (c == 's')
		count = ft_putstr((char *)va_arg(args, const char *));
	else if (c == 'p')
	{
		count = ft_putstr("0x");
		count += ft_put_adress((unsigned long)va_arg(args, void *),
				"0123456789abcdef");
	}
	else if (c == 'd' || c == 'i')
		count += ft_putnbr_base(va_arg(args, int), "0123456789");
	else if (c == 'u')
		count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	else if (c == 'x')
		count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	va_start(args, s);
	count = 0;
	while (s && *s)
	{
		if (*s == '%')
		{
			s++;
			count += format(*s, args);
		}
		else
			count += ft_putchar(*s);
		s++;
	}
	va_end(args);
	return (count);
}
