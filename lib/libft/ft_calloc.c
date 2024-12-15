/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:57:13 by achu              #+#    #+#             */
/*   Updated: 2024/11/06 15:57:14 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dst;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	dst = (void *)malloc(count * size);
	if (!dst)
		return (NULL);
	ft_bzero(dst, count * size);
	return (dst);
}
