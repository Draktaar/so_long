/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:44:12 by achu              #+#    #+#             */
/*   Updated: 2025/04/06 01:14:04 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Compare to see if the end of the string is find
int	ft_strnend(const char *str, char *find)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		j = 0;
		while (find[j] && (i + j) < len && str[i + j] == find[j])
			j++;
		if (!find[j] && str[i + j] == 0)
			return (1);
		i++;
	}
	return (0);
}
