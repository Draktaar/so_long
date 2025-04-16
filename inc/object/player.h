/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:09:45 by achu              #+#    #+#             */
/*   Updated: 2025/04/15 20:26:48 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

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
# define DASH_POW 250
# define DASH_TIME 0.15
# define DASH_CDR 0.3

// *** QoL ***
# define COYOTE 0.15
# define BUFFER 0.2

# include <stdbool.h>
# include "engine/input.h"
# include "engine/image.h"
# include "engine/timer.h"
# include "engine/vec.h"

typedef enum e_state
{
	IDLE,
	WALK,
	JUMP,
	SLIDE,
}	t_state;

typedef struct s_input
{
	bool	dash_pressed;
	bool	jump_pressed;
	bool	jump_hold;
	t_vec2	move;
}	t_input;

typedef struct s_player
{
	t_input		controller;
	t_sprite	sprite;
	t_vec2		start;
	t_vec2		position;
	t_vec2		velocity;
	t_vec2		remainder;
	t_rect		collider;

	t_rect		ground_col;
	bool		is_ground;

	bool		is_wall;
	
	bool		is_dashing;
	uint32_t	dash_limit;
	t_timer		dash_duration;
	t_timer		dash_cooldown;

	t_timer		jump_buffer;
	t_timer		coyote_time;
}	t_player;

t_player	init_player(void);
void		check_ground(t_player *player, t_rect wall);
void    	update_player(t_player *player, t_keybind *keybind, double delta);
void		update_collision(t_player *player, t_rect wall);

#endif