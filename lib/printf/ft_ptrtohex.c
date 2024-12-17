/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrtohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:40:39 by achu              #+#    #+#             */
/*   Updated: 2024/11/13 12:40:40 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrtohex(void *ptr)
{
	int					i;
	unsigned long long	adress;
	char				*hex;

	if (ptr == 0)
		return (ft_putstr("(nil)"));
	i = 0;
	adress = (unsigned long long)ptr;
	hex = ft_hexalloc(adress);
	i += ft_putstr("0x");
	i += ft_putstr(hex);
	free(hex);
	return (i);
}
