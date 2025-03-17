/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:50:57 by achu              #+#    #+#             */
/*   Updated: 2025/03/17 16:52:15 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio42.h"

static int	ft_format(va_list args, const char conv, int fd)
{
	int	i;

	i = 0;
	if (conv == 'c')
		i += ft_putchar(va_arg(args, int), fd);
	else if (conv == 's')
		i += ft_putstr(va_arg(args, char *), fd);
	else if (conv == 'p')
		i += ft_ptrtohex(va_arg(args, void *), fd);
	else if (conv == 'd')
		i += ft_putdec(va_arg(args, int), fd);
	else if (conv == 'i')
		i += ft_putint(va_arg(args, int), fd);
	else if (conv == 'u')
		i += ft_putudec(va_arg(args, unsigned int),fd);
	else if (conv == 'x')
		i += ft_puthexlow(va_arg(args, unsigned int), fd);
	else if (conv == 'X')
		i += ft_puthexup(va_arg(args, unsigned int), fd);
	else if (conv == '%')
		i += ft_putchar('%', fd);
	return (i);
}

int	ft_fprintf(int fd, const char *str, ...)
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
			i += ft_format(args, *str, fd);
		}
		else
			i += ft_putchar(*str, fd);
		str++;
	}
	va_end(args);
	return (i);
}