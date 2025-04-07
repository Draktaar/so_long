/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:03:42 by achu              #+#    #+#             */
/*   Updated: 2024/11/05 15:03:43 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int find, size_t size)
{
	size_t				i;
	const unsigned char	*mem;

	i = 0;
	mem = (const unsigned char *)str;
	while (i < size)
	{
		if (mem[i] == (unsigned char)find)
			return ((void *)str + i);
		i++;
	}
	return (NULL);
}
