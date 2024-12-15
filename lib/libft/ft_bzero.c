/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:20:49 by achu              #+#    #+#             */
/*   Updated: 2024/12/12 13:37:44 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

void	ft_bzero(void *str, size_t size)
{
	size_t			i;
	unsigned char	*string;

	i = 0;
	string = (unsigned char *)str;
	while (i < size)
	{
		string[i] = 0;
		i++;
	}
}
