/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pathfinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:43:34 by achu              #+#    #+#             */
/*   Updated: 2025/03/20 22:06:00 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map.h"

static const int	g_xdir[4] = {-1, 0, 1, 0};
static const int	g_ydir[4] = {0, -1, 0, 1};

// Return if the tile is or not a valid tile to traverse
static int	is_valid_path(t_map *manager, int x, int y)
{
	if (!(0 < x || x < manager->width))
		return (0);
	else if (!(0 < y || y < manager->width))
		return (0);
	else if (manager->map[y][x] == WALL)
		return (0);
	else if (manager->visited[y][x] == 1)
		return (0);
	return (1);
}

// Breadth-first search algo:
// Traverse the map in search for all the element in the map
static int	solve_path(t_map *manager, int x, int y)
{
	int	i;

	i = 0;
	manager->visited[y][x] = 1;
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
	return (0);
}

// Create a visited tile for the pathfinding algo in the same size of the
// current map and recursively do the breadth-first search algo,
// if the nb of coins and exit doesn't match with there max value return false
int	is_valid_pathfinder(t_map *manager)
{
	int	i;
	int	**temp;

	i = 0;
	temp = (int **)calloc(manager->height + 1, sizeof(int *));
	if (!temp)
		return (0);
	while (i < manager->height)
	{
		temp[i] = (int *)calloc(manager->width, sizeof(int));
		if (!temp[i])
			return (ft_freeptrs((void **)temp), 0);
		i++;
	}
	manager->visited = temp;
	solve_path(manager, manager->start.x, manager->start.y);
	if (manager->nb_coin != (*manager).max_coin)
		return (ft_perror("Error: Pathfinder didn't found all the coins"), 0);
	else if (manager->nb_exit != 1)
		return (ft_perror("Error: Pathfinder didn't found the exit"), 0);
	return (1);
}
