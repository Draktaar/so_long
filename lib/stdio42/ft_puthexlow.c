/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexlow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:16:41 by achu              #+#    #+#             */
/*   Updated: 2025/03/17 16:45:20 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio42.h"

int	ft_puthexlow(unsigned int nb, int fd)
{
	int		i;
	char	*hex;

	hex = ft_hexalloc(nb);
	if (!hex)
		return (0);
	i = ft_putstr(hex, fd);
	free(hex);
	return (i);
}
