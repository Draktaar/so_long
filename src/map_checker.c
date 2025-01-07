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

#include "libft.h"
#include "../includes/map.h"
#include "../includes/game.h"

int	check_tile(t_map *manager, int x, int y)
{
	if (!is_valid_char((*manager).map[y][x]))
		return (ft_putstr_fd("Invalid char used in the map file\n", 2), 0);
	else if (!is_valid_border(manager, x, y))
		return (ft_putstr_fd("Map not encased by walls\n", 2), 0);
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
		return (ft_putstr_fd("Map has more or less than one player\n", 2), 0);
	else if ((*manager).max_exit != 1)
		return (ft_putstr_fd("Map has more or less than one exit\n", 2), 0);
	else if ((*manager).max_coin == 0)
		return (ft_putstr_fd("Map must at least contain one coin\n", 2), 0);
	return (1);
}

int	is_valid_file(int argc, char *argv[])
{
	if (argc == 1)
		return (ft_putstr_fd("No arguments\n", 2), 0);
	else if (!is_filecmp(argv[1], ".ber"))
		return (0);
	else if (argc > 2)
		ft_putstr_fd("More than one argument, only the first will be used\n", 1);
	return (1);
}

int	init_setup(int argc, char *argv[])
{
	t_map	manager;

	if (!is_valid_file(argc, argv))
		return (0);
	manager = init_map_manager();
	manager.map = init_map(argv[1]);
	if (!manager.map)
		return (free(manager.map), 0);
	manager.width = ft_strlen(manager.map[0]) - 1;
	manager.height = ft_strdlen(manager.map);
	if (!is_valid_map(&manager))
		return (0);
	else if (!ft_pathfinder(&manager))
		return (0);
	return (1);
}

int	main(int argc, char const *argv[])
{
	t_game	game;

	if (!init_setup(argc, argv))
		return (0);
	ft_printf("%s\n", "big");
	return (1);
}
