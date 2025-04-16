/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:38:51 by achu              #+#    #+#             */
/*   Updated: 2025/04/16 16:50:37 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>
#include "player.h"

static double	ft_approach(double current, double target, double step)
{
	if (current < target)
		return (fminf(current + step, target));
	else if (current > target)
		return (fmaxf(current - step, target));
	else
		return (target);
}

void	player_direction(t_player *player, double delta)
{
	double	accel;
	double	turn;
	double	decel;

	accel = ACCEL;
	turn = TURN;
	decel = DECEL;
	if (!player->is_ground)
	{
		accel = AIR_ACCEL;
		turn = AIR_TURN;
		decel = AIR_DECEL;
	}
	if (player->controller.move.x == 0)
		player->velocity.x = ft_approach(player->velocity.x, 0, decel * delta);	
	else if (player->controller.move.x <= 0 && player->velocity.x > 0)
		player->velocity.x = ft_approach(player->velocity.x, 0, turn * delta);
	else if (player->controller.move.x >= 0 && player->velocity.x < 0)
		player->velocity.x = ft_approach(player->velocity.x, 0, turn * delta);
	else
		player->velocity.x = ft_approach(player->velocity.x, player->controller.move.x * MAX_SPEED, accel * delta);
}

void	player_gravity(t_player *player, double delta)
{
	float	mult;

	mult = FALL_MULT;
	if (!player->is_ground)
	{
		if (!player->controller.jump_hold && player->velocity.y < 0)
			mult = 3;
		player->velocity.y = ft_approach(player->velocity.y, MAX_FALL, GRAVITY * mult * delta);	
	}
}

void	player_jump(t_player *player, double delta)
{
	(void)delta;
	if (player->controller.jump_pressed && player->is_ground)
	{
		player->velocity.x += JUMP_BOOST * player->controller.move.x;
		player->velocity.y = -JUMP_POW;
	}
}

void	player_dash(t_player *player, double delta)
{
	if (player->controller.dash_pressed)
	{
		player->velocity.x = player->controller.move.x * DASH_POW;
		player->velocity.y = player->controller.move.y * DASH_POW;		
	}
}
