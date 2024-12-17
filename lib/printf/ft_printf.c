/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:14:54 by achu              #+#    #+#             */
/*   Updated: 2024/11/13 11:14:57 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, const char conv)
{
	int	i;

	i = 0;
	if (conv == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (conv == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (conv == 'p')
		i += ft_ptrtohex(va_arg(args, void *));
	else if (conv == 'd')
		i += ft_putdec(va_arg(args, int));
	else if (conv == 'i')
		i += ft_putint(va_arg(args, int));
	else if (conv == 'u')
		i += ft_putudec(va_arg(args, unsigned int));
	else if (conv == 'x')
		i += ft_puthexlow(va_arg(args, unsigned int));
	else if (conv == 'X')
		i += ft_puthexup(va_arg(args, unsigned int));
	else if (conv == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			i += ft_format(args, *str);
		}
		else
			i += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (i);
}
