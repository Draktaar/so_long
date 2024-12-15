/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:23:28 by achu              #+#    #+#             */
/*   Updated: 2024/12/12 13:26:59 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (find[0] == 0)
		return ((char *)str);
	while (str[i] && i < len)
	{
		j = 0;
		while (find[j] && (i + j) < len && str[i + j] == find[j])
			j++;
		if (!find[j])
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
