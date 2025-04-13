/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pathfinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:43:34 by achu              #+#    #+#             */
/*   Updated: 2025/04/13 01:52:31 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "map.h"

static const int	g_xdir[4] = {-1, 0, 1, 0};
static const int	g_ydir[4] = {0, -1, 0, 1};

// Return if the tile is or not a valid tile to traverse
static bool	is_valid_path(t_map *manager, int x, int y)
{
	if (!(0 < x || x < manager->width))
		return (false);
	else if (!(0 < y || y < manager->height))
		return (false);
	else if (manager->map[y][x] == WALL)
		return (false);
	else if (manager->visited[y][x] == true)
		return (false);
	return (true);
}

// Breadth-first search algo:
// Traverse the map in search for all the element in the map
static bool	solve_path(t_map *manager, int x, int y)
{
	int	i;

	i = 0;
	manager->visited[y][x] = true;
	if (manager->map[y][x] == COIN)
		manager->nb_coin++;
	else if (manager->map[y][x] == EXIT)
		manager->nb_exit++;
	while (i < 4)
	{
		if (is_valid_path(manager, x + g_xdir[i], y + g_ydir[i]))
			solve_path(manager, x + g_xdir[i], y + g_ydir[i]);
		i++;
	}
	return (false);
}

// Create a visited tile for the pathfinding algo in the same size of the
// current map and recursively do the breadth-first search algo,
// if the nb of coins and exit doesn't match with there max value return false
bool	is_valid_pathfinder(t_map *manager)
{
	int		i;
	bool	**temp;

	i = 0;
	temp = (bool**)calloc(manager->height + 1, sizeof(bool*));
	if (!temp)
		return (false);
	while (i < manager->height)
	{
		temp[i] = (int *)calloc(manager->width, sizeof(int));
		if (!temp[i])
			return (free_arr((void **)temp), false);
		i++;
	}
	manager->visited = temp;
	solve_path(manager, manager->start.x, manager->start.y);
	if (manager->nb_coin != (*manager).max_coin)
		return (ft_perror("Error: Pathfinder didn't found all the coins"), 0);
	else if (manager->nb_exit != 1)
		return (ft_perror("Error: Pathfinder didn't found the exit"), 0);
	return (true);
}
