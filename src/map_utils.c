/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:48:01 by achu              #+#    #+#             */
/*   Updated: 2024/12/18 21:29:21 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t	ft_strdlen(char **strd)
{
	size_t	i;

	i = 0;
	while (strd[i])
		i++;
	return (i);
}

int is_valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'C'  || c == 'E' || c == 'P')
		return (1);
	return (0);
}

int	is_unique_char()
{
	
}