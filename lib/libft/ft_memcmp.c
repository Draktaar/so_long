/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:15:15 by achu              #+#    #+#             */
/*   Updated: 2024/11/05 17:15:16 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *p1, const void *p2, size_t size)
{
	size_t				i;
	const unsigned char	*s1;
	const unsigned char	*s2;

	i = 0;
	s1 = (const unsigned char *)p1;
	s2 = (const unsigned char *)p2;
	while (i < size)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
