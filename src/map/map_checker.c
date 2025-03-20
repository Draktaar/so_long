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

// Check if the character is a usable char for the map
static int	is_valid_char(char c)
{
	if (c == WALL || c == EMPTY || c == COIN || c == EXIT || c == PLAYER)
		return (1);
	return (0);
}

// Check if the character is at the border
static int	is_valid_border(t_map *manager, int x, int y)
{
	int	h;
	int	w;

	h = (*manager).height - 1;
	w = (*manager).width - 1;
	if (x == 0 || y == 0 || x == w || y == h)
		if ((*manager).map[y][x] != WALL)
			return (0);
	return (1);
}

// Check for the current tile info
static int	is_valid_tile(t_map *manager, int x, int y)
{
	if (!is_valid_char(manager->map[y][x]))
		return (ft_perror("Error: Invalid char used in the map file"), 0);
	else if (!is_valid_border(manager, x, y))
		return (ft_perror("Error: Map not encased by walls"), 0);
	else if ((*manager).map[y][x] == PLAYER)
	{
		manager->max_player++;
		manager->start.x = x;
		manager->start.y = y;
	}
	else if (manager->map[y][x] == EXIT)
		manager->max_exit++;
	else if (manager->map[y][x] == COIN)
		manager->max_coin++;
	return (1);
}

// Traverse and check every tile of the map
// and return error if there is a missing asset in the map
int	is_valid_map(t_map *manager)
{
	int	x;
	int	y;

	y = 0;
	while (y < manager->height)
	{
		x = 0;
		while (x < manager->width)
		{
			if (!is_valid_tile(manager, x, y))
				return (0);
			x++;
		}
		y++;
	}
	if (manager->max_player != 1)
		return (ft_perror("Error: Map has more or less than one player"), 0);
	else if (manager->max_exit != 1)
		return (ft_perror("Error: Map has more or less than one exit"), 0);
	else if (manager->max_coin == 0)
		return (ft_perror("Error: Map must at least contain one coin"), 0);
	return (1);
}

// Check for a valid file map
int	is_valid_file(int argc, char **argv)
{
	int	fd;

	if (argc < 2)
		return (ft_perror("Error: No arguments"), 0);
	else if (argc > 2)
		ft_printf("More than one argument, only the first will be used\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_perror("Error: File cannot be opened"), 0);
	else if (!ft_strrend(argv[1], ".ber"))
		return (ft_perror("Error: File not compatible, use .ber file"), 0);
	close(fd);
	return (1);
}
