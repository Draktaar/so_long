/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexlow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:16:41 by achu              #+#    #+#             */
/*   Updated: 2024/11/13 15:16:41 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexlow(unsigned int nb)
{
	int		i;
	char	*hex;

	hex = ft_hexalloc(nb);
	if (!hex)
		return (0);
	i = ft_putstr(hex);
	free(hex);
	return (i);
}
