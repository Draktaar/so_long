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

#include "game.h"

void	player_direction(t_player *player, double delta);
void	player_gravity(t_player *player, double delta);
void	player_dash(t_player *player, double delta);
void	player_jump(t_player *player, double delta);


t_player	init_player(void)
{
	t_player	player;

	player.controller.dash_pressed = 0;
	player.controller.jump_hold = 0;
	player.controller.jump_pressed = 0;
	player.controller.move = (t_vec2){
		.x = 0,
		.y = 0,
	};
	player.pos = (t_vec2){
		.x = 16,
		.y = 16,
	};
	player.col = (t_rect){
		.pos = {0, 0},
		.size = {8,11}
	};
	player.ground_col = (t_rect){
		.pos = {0, 0},
		.size = {8, 3}
	};
	player.is_ground = false;
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
	player_direction(player, delta);
	player_dash(player, delta);
	player_jump(player, delta);
	player_gravity(player, delta);

	player->pos.x += player->vel.x * delta;
	player->pos.y += player->vel.y * delta;
	player->col.pos.x = player->pos.x - player->col.size.x / 2;
	player->col.pos.y = player->pos.y - player->col.size.y / 2;
	player->ground_col.pos.x = player->col.pos.x;
	player->ground_col.pos.y = player->col.pos.y + player->col.size.y;
}
