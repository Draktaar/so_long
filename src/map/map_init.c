/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:14:10 by achu              #+#    #+#             */
/*   Updated: 2025/04/18 16:32:04 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "map.h"

static t_map	init_map(void)
{
	t_map	grid;

	grid.height = 0;
	grid.width = 0;
	grid.grid = NULL;
	grid.visited = NULL;
	grid.player_pos = (t_vec2){0, 0};
	grid.max_player = 0;
	grid.heart_pos = (t_vec2){0, 0};
	grid.max_heart = 0;
	grid.solid_pos = NULL;
	grid.max_solid = 0;
	grid.berry_pos = NULL;
	grid.max_berry = 0;
	grid.found_exit = 0;
	grid.found_berry = 0;
	return (grid);
}

void	clean_map(t_map *grid)
{
	free_arr((void **)grid->grid);
	free_arr((void **)grid->visited);
	free_ptr((void *)grid->solid_pos);
	free_ptr((void *)grid->berry_pos);
}

int	setup_map(t_map *grid, int argc, char **argv)
{
	if (!is_valid_file(argc, argv))
		return (0);
	*grid = init_map();
	grid->grid = parse_map(argv[1]);
	if (!grid->grid)
		return (ft_perror("Map not initialize"), 0);
	grid->width = ft_strlen(grid->grid[0]) - 1;
	grid->height = ft_arrlen(grid->grid);
	if (!is_valid_map(grid))
		return (clean_map(grid), 0);
	else if (!is_valid_pathfinder(grid))
		return (clean_map(grid), 0);
	return (1);
}
