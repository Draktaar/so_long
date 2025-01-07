/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:59:08 by achu              #+#    #+#             */
/*   Updated: 2024/12/20 17:09:59 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_map
{
    char    **map;
    int     height;
    int     width;

    int     nb_player;
    int     nb_exit;
    int     nb_coin;
}   t_map;

int is_valid_char(char c);
int	is_filecmp(const char *file, const char *find);

#endif