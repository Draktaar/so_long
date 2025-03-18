/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrtohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:40:39 by achu              #+#    #+#             */
/*   Updated: 2025/03/17 16:44:31 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio42.h"

int	ft_ptrtohex(void *ptr, int fd)
{
	int					i;
	unsigned long long	adress;
	char				*hex;

	if (ptr == 0)
		return (ft_putstr("(nil)", fd));
	i = 0;
	adress = (unsigned long long)ptr;
	hex = ft_hexalloc(adress);
	i += ft_putstr("0x", fd);
	i += ft_putstr(hex, fd);
	free(hex);
	return (i);
}
