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

// *** Movement ***
# define ACCEL 1200
# define TURN 1200
# define DECEL 600
# define MAX_SPEED 90

// *** Jump ***
# define JUMP_POW 175
# define JUMP_BOOST 50
# define JUMP_CUT 5
# define AIR_ACCEL 1000
# define AIR_TURN 500
# define AIR_DECEL 250

// *** Gravity ***
# define GRAVITY 410
# define GROUND_FORCE 100
# define FALL_MULT 1.5
# define MAX_FALL 160

// *** Dash ***
# define MAX_DASH 1
# define DASH_POW 200
# define DASH_TIME 0.15
# define DASH_CDR 0.3

// *** QoL ***
# define COYOTE 0.15
# define BUFFER 0.2

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <time.h>
# include "engine.h"
# include "../inc/object/player.h"
# include "../inc/object/berry.h"
# include "../inc/object/solid.h"
# include "../inc/object/spike.h"

typedef struct s_system
{
	t_display	display;
	t_img		buffer;
	t_img		screen;
	t_keybind	*input;

	double		late;
	double		delta;

	t_solid		*solids;

	t_player	player;
	t_rect		wall;

	int			step;
	int			score;
	int			coins;
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
t_display	setup_window(int height, int width);

int		start(t_system *manager);

t_solid	*init_solid(t_display window, char **map);

void	render(t_system *game);
t_img	new_xpm(t_display window, char *file);
t_img	new_img(t_display window, int h, int w);
void	draw_square(t_img *image, t_rect rect, int color);
void	draw_rect(t_img *image, t_rect rect, int color);
unsigned int	get_pixel(t_img *img, int x, int y);
void	ft_pixel_put(t_img *img, int x, int y, int color);
void	draw_bg(t_img *game);
void	pixel_scale(t_img *src, t_img *dst, int scale);

#endif
