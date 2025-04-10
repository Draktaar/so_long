/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:11:06 by achu              #+#    #+#             */
/*   Updated: 2025/01/07 16:59:22 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <time.h>
# include "engine.h"
# include "../inc/object/player.h"
# include "../inc/object/object.h"

typedef struct s_system
{
	t_display	display;
	t_img		screen;
	t_img		game;
	t_keybind	*input;
	double		last;
	double		delta;

	t_player	player;
	t_solid		*solids;
}	t_system;

typedef struct s_game
{
	t_player	player;
	t_solid		*solids;
	t_berry		*berries;

	uint32_t	timer;
	uint32_t	score;
}	t_game;

// Window
t_display	setup_window(void);

int		start(t_system *manager);

void	render(t_system *game);
void	ft_pixel_put(t_img *img, int x, int y, int color);
unsigned int	get_pixel(t_img *img, int x, int y);
void	pixel_scale(t_img *src, t_img *dst, int scale);

// *** Gizmo tools ***
void	draw_bg(t_img *game);
void	draw_square(t_img *image, t_rect rect, int color);
void	draw_rect(t_img *image, t_rect rect, int color);

#endif
