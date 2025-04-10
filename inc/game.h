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

typedef struct s_img
{
	t_display	window;
	void		*ptr;
	char		*addr;
	int			h;
	int			w;
	int			bpp;
	int			llen;
	int			endian;
}	t_img;

typedef struct s_sprite
{
	t_img	img;
}	t_sprite;


typedef struct s_input
{
	bool	dash_pressed;
	bool	jump_pressed;
	bool	jump_hold;
	t_vec2	move;
}	t_input;

typedef enum e_state
{
	IDLE,
	WALK,
	JUMP,
}	t_state;

typedef struct s_player
{
	t_input		controller;
	t_sprite	sprite;
	t_vec2		position;
	t_vec2		velocity;
	t_rect		collider;
	t_rect		ground_col;
	bool		is_ground;
	bool		is_grab;
}	t_player;

typedef struct s_wall
{
	t_sprite		sprite;
	t_rect			collider;
}	t_wall;

typedef struct s_game
{
	t_display	display;
	t_keybind	*input;
	t_img		buffer;
	t_img		screen;


	double		late;
	double		delta;

	t_wall		*solids;

	t_player	player;
	t_rect		wall;

	int			step;
	int			score;
	int			coins;
}	t_game;

// Window
t_display	setup_window(int height, int width);


int		start(t_game *manager);
t_player	init_player(void);

void	check_collision(t_player *player, t_wall wall);
void    update_player(t_player *player, t_keybind *keybind, double delta);
void	update_collision(t_player *player, t_wall wall);

t_wall	*init_solid(t_display window, char **map);

t_img	new_xpm(t_display window, char *file);
t_img	new_img(t_display window, int h, int w);
void	draw_square(t_img *image, t_rect rect, int color);
void	draw_rect(t_img *image, t_rect rect, int color);
unsigned int	get_pixel(t_img *img, int x, int y);
void			ft_pixel_put(t_img *img, int x, int y, int color);
void	draw_bg(t_img *game);
void	blit_scaled(t_img *src, t_img *dst, int scale);

#endif
