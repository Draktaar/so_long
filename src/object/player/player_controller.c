/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:07:47 by achu              #+#    #+#             */
/*   Updated: 2025/01/07 10:31:35 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/input.h"
#include "player.h"

void	player_direction(t_player *player, double delta);
void	player_gravity(t_player *player, double delta);
void	player_dash(t_player *player, double delta);
void	player_jump(t_player *player, double delta);

t_player	init_player(t_map grid)
{
	t_player	player;

	player.controller.dash_pressed = 0;
	player.controller.jump_hold = 0;
	player.controller.jump_pressed = 0;
	player.controller.move = (t_vec2){.x = 0.0f, .y = 0.0f,};
	player.position = (t_vec2){
		.x = grid.player_pos.x * PIXEL_SIZE,
		.y = grid.player_pos.y * PIXEL_SIZE,
	};
	player.velocity = (t_vec2){.x = 0.0f, .y = 0.0f,};
	player.remainder = (t_vec2){.x = 0.0f, .y = 0.0f,};
	player.collider = (t_rect){.pos = player.position, .size = {8, 11}};
	player.is_right = false;
	player.ground_col = (t_rect){.pos = player.position, .size = {8, 3}};
	player.is_grounded = false;
	player.dash_limit = 0;
	player.dash_cooldown = 0;
	player.dash_duration = 0;
	player.is_dashing = false;
	return (player);
}

static void	player_input(t_input *controller, t_keybind *keybind)
{
	controller->move.x = 0;
	controller->move.y = 0;
	if (keybind[D].hold)
		controller->move.x += 1;
	if (keybind[A].hold)
		controller->move.x -= 1;
	if (keybind[W].hold)
		controller->move.y -= 1;
	if (keybind[S].hold)
		controller->move.y += 1;
	controller->jump_hold = keybind[SPACE].hold;
	controller->jump_pressed = keybind[SPACE].pressed;
	controller->dash_pressed = keybind[SHIFT].pressed;
}

void	update_player(t_player *player, t_keybind *keybind, double delta)
{
	player_input(&player->controller, keybind);
	if (player->controller.move.x == 1)
		player->is_right = true;
	else if (player->controller.move.x == -1)
		player->is_right = false;
	player_direction(player, delta);
	player_dash(player, delta);
	player_jump(player, delta);
	player_gravity(player, delta);
}

void	check_ground(t_player *player, t_rect wall)
{
	if (!player->is_grounded && is_collided(player->ground_col, wall))
	{
		player->is_grounded = true;
	}
	else if (player->is_grounded && !is_collided(player->ground_col, wall))
	{
		player->is_grounded = false;
	}
}
