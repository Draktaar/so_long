/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:09:45 by achu              #+#    #+#             */
/*   Updated: 2025/04/10 15:39:00 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "engine.h"

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
	t_vec2		pos;
	t_vec2		vel;
	t_rect		col;
	t_rect		ground_col;
	bool		is_ground;
	bool		is_grab;
}	t_player;

t_player	init_player(void);
void		check_collision(t_player *player, t_solid wall);
void    	update_player(t_player *player, t_keybind *keybind, double delta);
void		update_collision(t_player *player, t_solid wall);

#endif