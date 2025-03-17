/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:47:43 by achu              #+#    #+#             */
/*   Updated: 2025/01/07 16:23:14 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "map.h"

int	check_tile(t_map *manager, int x, int y)
{
	if (!is_valid_char((*manager).map[y][x]))
		return (ft_perror("Invalid char used in the map file"), 0);
	else if (!is_valid_border(manager, x, y))
		return (ft_perror("Map not encased by walls"), 0);
	else if ((*manager).map[y][x] == PLAYER)
	{
		manager->max_player++;
		manager->start.x = x;
		manager->start.y = y;
	}
	else if ((*manager).map[y][x] == EXIT)
		manager->max_exit++;
	else if ((*manager).map[y][x] == COIN)
		manager->max_coin++;
	return (1);
}

int	is_valid_map(t_map *manager)
{
	int	x;
	int	y;

	y = 0;
	while (y < (*manager).height)
	{
		x = 0;
		while (x < (*manager).width)
		{
			if (!check_tile(manager, x, y))
				return (0);
			x++;
		}
		y++;
	}
	if ((*manager).max_player != 1)
		return (ft_perror("Map has more or less than one player"), 0);
	else if ((*manager).max_exit != 1)
		return (ft_perror("Map has more or less than one exit"), 0);
	else if ((*manager).max_coin == 0)
		return (ft_perror("Map must at least contain one coin"), 0);
	return (1);
}

int	is_valid_file(int argc, char *argv[])
{
	if (argc == 1)
		return (ft_perror("No arguments"), 0);
	else if (!is_filecmp(argv[1], ".ber"))
		return (0);
	else if (argc > 2)
		ft_perror("More than one argument, only the first will be used");
	return (1);
}

int	init_setup(t_map *manager, int argc, char *argv[])
{
	if (!is_valid_file(argc, argv))
		return (0);
	(*manager) = init_mapmanager();
	manager->map = init_map(argv[1]);
	if (!(*manager).map)
		return (free((*manager).map), 0);
	manager->width = ft_strlen((*manager).map[0]) - 1;
	manager->height = ft_strdlen((*manager).map);
	if (!is_valid_map(manager))
		return (0);
	else if (!ft_pathfinder(manager))
		return (0);
	return (1);
}
