/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:59:08 by achu              #+#    #+#             */
/*   Updated: 2025/01/10 16:06:07 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "engine.h"

typedef struct s_map
{
    char    **map;
    int     **visited;
    int     height;
    int     width;

    t_vector2   start;
    int         max_player;
    int         max_exit;
    int         max_coin;

    int         nb_exit;
    int         nb_coin;
}   t_map;

t_map	init_mapmanager();
int	    ft_pathfinder(t_map *manager);
int     is_valid_char(char c);
int     is_valid_border(t_map *manager, int x, int y);
int 	is_filecmp(const char *file, const char *find);
size_t	ft_strdlen(char **strd);

#endif