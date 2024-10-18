/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:53:54 by agenc             #+#    #+#             */
/*   Updated: 2022/11/14 14:20:15 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_control(char c, va_list arg)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		i += ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		i += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		i += ft_u(va_arg(arg, unsigned int));
	else if (c == 'x')
		i += ft_x(va_arg(arg, unsigned int), 0);
	else if (c == 'X')
		i += ft_x(va_arg(arg, unsigned int), 1);
	else if (c == 'p')
	{
		i += write (1, "0x", 2);
		i += ft_p(va_arg(arg, unsigned long));
	}
	else if (c == '%')
		i += ft_putchar('%');
	else
		return (ft_putchar(c));
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;
	int		len;

	va_start(arg, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			ft_putchar(s[i]);
			len++;
		}
		if (s[i] == '%')
		{
			i++;
			while (s[i] == ' ' && s[i])
				i++;
			len += ft_control(s[i], arg);
		}
		i++;
	}
	va_end(arg);
	return (len);
}
