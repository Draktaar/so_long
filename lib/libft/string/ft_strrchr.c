/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:08:38 by achu              #+#    #+#             */
/*   Updated: 2025/04/06 01:13:14 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Compare to see if the string has the char [find]
char	*ft_strrchr(const char *str, int find)
{
	int	i;

	i = ft_strlen((char *)str);
	while (i >= 0)
	{
		if (str[i] == (unsigned char)find)
			return ((char *)str + i);
		i--;
	}
	if (find == '\0')
		return ((char *)str + i);
	return (NULL);
}
