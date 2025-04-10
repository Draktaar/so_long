/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:38:51 by achu              #+#    #+#             */
/*   Updated: 2025/04/10 14:38:53 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static double	ft_approach(double current, double target, double step)
{
	if (current < target)
		return (fmin(current + step, target));
	else if (current > target)
		return (fmax(current - step, target));
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
		player->vel.x = ft_approach(player->vel.x, 0, decel * delta);	
	else if (player->controller.move.x <= 0 && player->vel.x > 0)
		player->vel.x = ft_approach(player->vel.x, 0, turn * delta);
	else if (player->controller.move.x >= 0 && player->vel.x < 0)
		player->vel.x = ft_approach(player->vel.x, 0, turn * delta);
	else
		player->vel.x = ft_approach(player->vel.x, player->controller.move.x * MAX_SPEED, accel * delta);
}

void	player_gravity(t_player *player, double delta)
{
	float	mult;

	mult = FALL_MULT;
	if (!player->is_ground)
	{
		if (!player->controller.jump_hold && player->vel.y < 0)
			mult = 3;
		player->vel.y = ft_approach(player->vel.y, MAX_FALL, GRAVITY * mult * delta);	
	}
}

void	player_jump(t_player *player, double delta)
{
	if (player->controller.jump_pressed && player->is_ground)
	{
		player->vel.x += JUMP_BOOST * player->controller.move.x;
		player->vel.y = -JUMP_POW;
	}
}

void	player_dash(t_player *player, double delta)
{
	if (player->controller.dash_pressed)
	{
		player->vel.x = player->controller.move.x * DASH_POW;
		player->vel.y = player->controller.move.y * DASH_POW;
	}
}
