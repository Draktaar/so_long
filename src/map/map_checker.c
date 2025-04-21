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

#include "common.h"
#include "map.h"

// Check if the character is a usable char for the map
static bool	is_valid_char(char c)
{
	if (c == WALL || c == EMPTY || c == COIN || c == EXIT || c == PLAYER || c == SPIKE)
		return (true);
	return (false);
}

// Check if the character is at the border
static bool	is_valid_border(t_map *manager, int x, int y)
{
	int	height;
	int	width;

	height = (*manager).height - 1;
	width = (*manager).width - 1;
	if (x == 0 || y == 0 || x == width || y == height)
		if ((*manager).grid[y][x] != WALL)
			return (false);
	return (true);
}

static	int32_t	add_object(t_vec2 **pos, int32_t *size, int x, int y)
{
	t_vec2	*new_pos;
	size_t	new_size;

	new_size = *size + 1;
	new_pos = ft_realloc(*pos, *size * sizeof(t_vec2), new_size * sizeof(t_vec2));
	if (!new_pos)
		return (0);
	new_pos[*size] = (t_vec2){x, y};
	(*pos) = new_pos;
	(*size) = new_size;
	return (1);
}

// Check for the current tile info
static bool	is_valid_tile(t_map *manager, int x, int y)
{
	if (!is_valid_char(manager->grid[y][x]))
		return (ft_perror("Error: Invalid char used in the map file"), false);
	else if (!is_valid_border(manager, x, y))
		return (ft_perror("Error: Map not encased by walls"), false);
	else if (manager->grid[y][x] == PLAYER)
	{
		manager->max_player++;
		manager->player_pos.x = x;
		manager->player_pos.y = y;
	}
	else if (manager->grid[y][x] == EXIT)
	{
		manager->max_heart++;
		manager->heart_pos.x = x;
		manager->heart_pos.y = y;
	}
	else if (manager->grid[y][x] == COIN)
		add_object(&manager->berry_pos, &manager->max_berry, x, y);
	else if (manager->grid[y][x] == WALL)
		add_object(&manager->solid_pos, &manager->max_solid, x, y);
	else if (manager->grid[y][x] == SPIKE)
		add_object(&manager->spike_pos, &manager->max_spike, x, y);
	return (true);
}

// Traverse and check every tile of the map
// and return error if there is a missing asset in the map
bool	is_valid_map(t_map *manager)
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
		return (ft_perror("Error: Map has more or less than one player"), false);
	else if (manager->max_heart != 1)
		return (ft_perror("Error: Map has more or less than one exit"), false);
	else if (manager->max_berry == 0)
		return (ft_perror("Error: Map must at least contain one coin"), false);
	return (true);
}

// Check for a valid file map
bool	is_valid_file(int argc, char **argv)
{
	int	fd;

	if (argc < 2)
		return (ft_perror("Error: No arguments"), false);
	else if (argc > 2)
		ft_printf("More than one argument, only the first will be used\n");
	if (access(argv[1], F_OK | R_OK) < 0)
		return (ft_perror("Error: Cannot read file"), false);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_perror("Error: File cannot be opened"), false);
	else if (!ft_strnend(argv[1], ".ber"))
		return (ft_perror("Error: File not compatible, use .ber file"), false);
	close(fd);
	return (true);
}
