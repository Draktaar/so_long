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
# define MAX_SPEED 10
# define ACCEL 250
# define GROUND_DECCEL 120
# define AIR_DECCEL 30

// *** Jump ***
# define JUMP_POW 2
# define MAX_FALL 10
# define FALL_ACCEL 10

// *** Gravity ***
# define GRAVITY 100
# define GRAVITY_APEX 10

// *** Dash ***
# define MAX_DASH 1
# define DASH_POW 30
# define DASH_TIME 0.15
# define DASH_CDR 0.3

// *** QoL ***
# define COYOTE 0.15
# define BUFFER 0.2

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

typedef struct s_player
{
	t_img		sprite;
	t_vec2		position;
	t_vec2		velocity;
	t_rect		collider;
}	t_player;

typedef struct s_game
{
	t_display	display;
	t_input		*input;

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
int 	draw_rect(t_display *data, t_rect rect, int color);
int 	draw_rect_line(t_display *data, t_rect rect, int color);
void    update_player(t_player *player, t_input *keybind, double delta);
void	update_horizontal(t_player *player, t_rect wall);

#endif
