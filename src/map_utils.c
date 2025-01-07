/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:48:01 by achu              #+#    #+#             */
/*   Updated: 2024/12/20 17:20:51 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
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
	if (c == WALL || c == EMPTY || c == COLLECTIBLE  || c == EXIT || c == PLAYER)
		return (1);
	return (0);
}

t_map	init_map_manager()
{
	t_map	manager;

	manager.height = 0;
	manager.width = 0;
	manager.map = NULL;
	manager.nb_player = 0;
	manager.nb_exit = 0;
	manager.nb_coin = 0;
	return (manager);
}

int	is_filecmp(const char *file, const char *find)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (file[i])
	{
		j = 0;
		while (find[j] && (i + j) < len && file[i + j] == find[j])
			j++;
		if (!find[j])
			return (1);
		i++;
	}
	return (0);
}