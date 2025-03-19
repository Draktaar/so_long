/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:14:54 by achu              #+#    #+#             */
/*   Updated: 2025/03/17 16:48:10 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio42.h"

static int	ft_format(va_list args, const char conv)
{
	int	i;

	i = 0;
	if (conv == 'c')
		i += ft_putchar(va_arg(args, int), STDOUT_FILENO);
	else if (conv == 's')
		i += ft_putstr(va_arg(args, char *), STDOUT_FILENO);
	else if (conv == 'p')
		i += ft_ptrtohex(va_arg(args, void *), STDOUT_FILENO);
	else if (conv == 'd')
		i += ft_putdec(va_arg(args, int), STDOUT_FILENO);
	else if (conv == 'i')
		i += ft_putint(va_arg(args, int), STDOUT_FILENO);
	else if (conv == 'u')
		i += ft_putudec(va_arg(args, unsigned int),STDOUT_FILENO);
	else if (conv == 'x')
		i += ft_puthexlow(va_arg(args, unsigned int), STDOUT_FILENO);
	else if (conv == 'X')
		i += ft_puthexup(va_arg(args, unsigned int), STDOUT_FILENO);
	else if (conv == '%')
		i += ft_putchar('%', STDOUT_FILENO);
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
			i += ft_putchar(*str, STDOUT_FILENO);
		str++;
	}
	va_end(args);
	return (i);
}
