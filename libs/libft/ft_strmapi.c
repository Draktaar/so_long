/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:19:24 by achu              #+#    #+#             */
/*   Updated: 2024/11/06 15:19:25 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *src, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc((ft_strlen((char *)src) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (src[i] != '\0')
	{
		str[i] = (*f)(i, src[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
