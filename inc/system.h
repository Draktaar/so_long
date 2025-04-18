/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:20:11 by achu              #+#    #+#             */
/*   Updated: 2025/04/17 14:21:40 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEM_H
# define SYSTEM_H

# include "engine/window.h"
# include "engine/image.h"
# include "engine/input.h"
# include "game.h"

typedef struct s_system
{
	t_display	window;
	t_img		scale;
	t_img		buffer;
	t_keybind	*input;
	t_game		*game;
	double		last;
	double		delta;
}	t_system;

t_system	*init_system(void);

#endif