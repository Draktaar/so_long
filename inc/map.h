/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:59:08 by achu              #+#    #+#             */
/*   Updated: 2025/01/07 15:37:05 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdbool.h>
# include "engine/vec.h"

typedef enum e_tile
{
	EMPTY = '0',
	WALL = '1',
	COIN = 'C',
	EXIT = 'E',
	SPIKE = 'S',
	PLAYER = 'P',
}	t_tile;

typedef struct s_map
{
	int			height;
	int			width;
	char		**grid;
	bool		**visited;

	t_vec2		player_pos;
	int32_t		max_player;

	t_vec2		heart_pos;
	int32_t		max_heart;

	t_vec2		*berry_pos;
	int32_t		max_berry;

	t_vec2		*solid_pos;
	int32_t		max_solid;

	t_vec2		*spike_pos;
	int32_t		max_spike;

	int32_t		found_exit;
	int32_t		found_berry;
}	t_map;

int		setup_map(t_map *manager, int argc, char **argv);
bool	is_valid_map(t_map *manager);
bool	is_valid_file(int argc, char **argv);
bool	is_valid_pathfinder(t_map *manager);
char	**parse_map(char *file);
void	clean_map(t_map *manager);

#endif