/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:59:08 by achu              #+#    #+#             */
/*   Updated: 2025/01/07 10:15:47 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "engine.h"

typedef struct s_queue
{
    t_vector2        pos;
    struct s_queue    *next;
}    t_queue;

typedef struct s_map
{
    char    **map;
    int     height;
    int     width;

    t_vector2   start;
    int         max_player;
    int         max_exit;
    int         max_coin;

    int         nb_exit;
    int         nb_coin;
}   t_map;

int is_valid_char(char c);
int	is_filecmp(const char *file, const char *find);

#endif