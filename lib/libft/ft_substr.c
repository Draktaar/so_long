/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:13:17 by achu              #+#    #+#             */
/*   Updated: 2024/11/06 14:13:18 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int pos, size_t size)
{
	size_t	i;
	size_t	len;
	char	*sub;

	i = 0;
	len = (size_t)ft_strlen(str);
	if (len < pos)
		return (ft_strdup(""));
	if (len - pos < size)
		size = len - pos;
	sub = (char *)malloc((size + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (str[pos + i] != '\0' && i < size)
	{
		sub[i] = str[pos + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}
