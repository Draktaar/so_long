/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pathfinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:43:34 by achu              #+#    #+#             */
/*   Updated: 2025/04/14 16:50:06 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "map.h"

static const int	g_xdir[4] = {-1, 0, 1, 0};
static const int	g_ydir[4] = {0, -1, 0, 1};

// Return if the tile is or not a valid tile to traverse
static bool	is_valid_path(t_map *grid, int x, int y)
{
	if (!(0 < x || x < grid->width))
		return (false);
	else if (!(0 < y || y < grid->height))
		return (false);
	else if (grid->grid[y][x] == WALL)
		return (false);
	else if (grid->visited[y][x] == true)
		return (false);
	return (true);
}

// Breadth-first search algo:
// Traverse the map in search for all the element in the map
static bool	solve_path(t_map *grid, int x, int y)
{
	int	i;

	i = 0;
	grid->visited[y][x] = true;
	if (grid->grid[y][x] == COIN)
		grid->found_berry++;
	else if (grid->grid[y][x] == EXIT)
		grid->found_exit++;
	while (i < 4)
	{
		if (is_valid_path(grid, x + g_xdir[i], y + g_ydir[i]))
			solve_path(grid, x + g_xdir[i], y + g_ydir[i]);
		i++;
	}
	return (false);
}

// Create a visited tile for the pathfinding algo in the same size of the
// current map and recursively do the breadth-first search algo,
// if the nb of coins and exit doesn't match with there max value return false
bool	is_valid_pathfinder(t_map *grid)
{
	int		i;
	bool	**temp;

	i = 0;
	temp = (bool **)calloc(grid->height + 1, sizeof(bool *));
	if (!temp)
		return (false);
	while (i < grid->height)
	{
		temp[i] = (bool *)calloc(grid->width, sizeof(bool));
		if (!temp[i])
			return (free_arr((void **)temp), false);
		i++;
	}
	grid->visited = temp;
	solve_path(grid, grid->player_pos.x, grid->player_pos.y);
	if (grid->found_berry != (*grid).max_berry)
		return (ft_perror("Error: Pathfinder didn't found all the coins"), 0);
	else if (grid->found_exit != 1)
		return (ft_perror("Error: Pathfinder didn't found the exit"), 0);
	return (true);
}
