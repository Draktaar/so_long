/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:16:33 by achu              #+#    #+#             */
/*   Updated: 2025/03/17 16:45:30 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio42.h"

static int	ft_toupper(int c)
{
	if (97 <= c && c <= 122)
		return (c - 32);
	return (c);
}

int	ft_puthexup(unsigned int nb, int fd)
{
	int		i;
	char	*hex;

	i = 0;
	hex = ft_hexalloc(nb);
	while (hex[i])
	{
		hex[i] = ft_toupper(hex[i]);
		i++;
	}
	i = ft_putstr(hex, fd);
	free(hex);
	return (i);
}
