/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:18:20 by achu              #+#    #+#             */
/*   Updated: 2024/12/12 13:24:22 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *ptr, int value, size_t size)
{
	size_t			i;
	unsigned char	*pointer;

	i = 0;
	pointer = ptr;
	while (i < size)
	{
		pointer[i] = (unsigned char)value;
		i++;
	}
	return (pointer);
}
