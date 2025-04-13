/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:20:11 by achu              #+#    #+#             */
/*   Updated: 2025/04/12 21:07:41 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEM_H
# define SYSTEM_H

# include "game.h"
# include "map.h"

typedef struct s_system
{
	t_display	display;
	t_img		scale;
	t_img		buffer;
	t_keybind	*input;
	t_map		*map;
	t_game		*game;
	double		last;
	double		delta;
}	t_system;

int		start(t_system *manager);

#endif