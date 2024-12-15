/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:56:31 by achu              #+#    #+#             */
/*   Updated: 2024/12/12 13:26:23 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strchr(const char *str, int find)
{
	unsigned char	fd;

	fd = (unsigned char)find;
	while (*str)
	{
		if ((unsigned char)*str == fd)
			return ((char *)str);
		str++;
	}
	if (fd == 0)
		return ((char *)str);
	return (NULL);
}
