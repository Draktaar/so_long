/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:38:51 by achu              #+#    #+#             */
/*   Updated: 2025/03/25 00:24:24 by achu             ###   ########.fr       */
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
	if (!player->is_grounded)
	{
		accel = AIR_ACCEL;
		turn = AIR_TURN;
		decel = AIR_ACCEL;
	}
	if (player->controller.move.x == 0)
		player->velocity.x = ft_approach(player->velocity.x, 0, decel * delta);
	else if (player->controller.move.x < 0 && player->velocity.x > 0)
		player->velocity.x = ft_approach(player->velocity.x, 0, turn * delta);
	else if (player->controller.move.x > 0 && player->velocity.x < 0)
		player->velocity.x = ft_approach(player->velocity.x, 0, turn * delta);
	else
		player->velocity.x = ft_approach(player->velocity.x, player->controller.move.x * MAX_SPEED, accel * delta);
}

void	player_gravity(t_player *player, double delta)
{
	if (!player->is_grounded)
		player->velocity.y = ft_approach(player->velocity.y, MAX_FALL, GRAVITY * delta);
}

void	player_jump(t_player *player, double delta)
{
	if (player->controller.jump_pressed && player->is_grounded && player->velocity.y == 0)
		player->velocity.y = -JUMP_POW;
}
