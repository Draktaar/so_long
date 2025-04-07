/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:57:09 by achu              #+#    #+#             */
/*   Updated: 2024/11/05 14:57:10 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;
	size_t	len;

	i = 0;
	len_src = ft_strlen((char *)src);
	len = ft_strlen(dst);
	if (size == 0)
		return (len_src);
	while (src[i] != '\0' && len + i < size - 1)
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	if (len < size)
		return (len + len_src);
	return (size + len_src);
}
