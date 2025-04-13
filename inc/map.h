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
	PLAYER = 'P',
}	t_tile;

typedef struct s_map
{
	int			height;
	int			width;

	char		**map;
	bool		**visited;

	t_vec2		start;
	t_vec2		exit;

	int			max_player;
	int			max_exit;
	int			max_coin;

	int			nb_exit;
	int			nb_coin;
}	t_map;

int		init_map(t_map *manager, int argc, char **argv);
bool	is_valid_map(t_map *manager);
bool	is_valid_file(int argc, char **argv);
bool	is_valid_pathfinder(t_map *manager);
char	**parse_map(char *file);
void	clean_map(t_map *manager);

#endif