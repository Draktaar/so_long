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
# define ACCEL 1000 * 3
# define TURN 700 * 3
# define DECEL 600 * 3
# define MAX_SPEED 90 * 3

// *** Jump ***
# define JUMP_POW 200 * 3
# define AIR_ACCEL 2000 * 3
# define AIR_TURN 300 * 3
# define AIR_DECEL 200 * 3

// *** Gravity ***
# define GRAVITY 900 * 3
# define GRAVITY_APEX 10
# define GROUND_FORCE 100
# define FALL_ACCEL 10
# define MAX_FALL 160 * 3

// *** Dash ***
# define MAX_DASH 1
# define DASH_POW 30
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
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		h;
	int		w;
}	t_img;

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
	t_vec2		position;
	t_vec2		velocity;
	t_rect		collider;
	t_rect		ground_col;
	bool		is_grounded;
}	t_player;

typedef struct s_game
{
	t_display	display;
	t_keybind		*input;

	double		late;
	double		delta;

	char		**map;

	t_player	player;
	t_rect		wall;

	int			step;
	int			score;
	int			coins;
}	t_game;

int		start(t_game *manager);
t_player	init_player(void);
int 	draw_rect(t_display *data, t_rect rect, int color);
int 	draw_rect_line(t_display *data, t_rect rect, int color);
void	check_collision(t_player *player, t_rect wall);
void    update_player(t_player *player, t_keybind *keybind, double delta);
void	update_collision(t_player *player, t_rect wall);
double	ft_abs(double val);

#endif
