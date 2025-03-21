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

void    player_movement(t_vec2 *velocity, t_input *keybind, double delta)
{
    velocity->y += GRAVITY * FALL_ACCEL * delta;
    if (keybind[MOVE_UP].hold)
        velocity->y -= ACCEL * delta;
    if (keybind[MOVE_DOWN].hold)
        velocity->y += ACCEL * delta;
    if (keybind[MOVE_LEFT].hold)
        velocity->x -= ACCEL * delta;
    if (keybind[MOVE_RIGHT].hold)
        velocity->x += ACCEL * delta;
    if (keybind[JUMP].pressed)
        velocity->y -= JUMP;
    
}

void    update_player(t_player *player, t_input *keybind, double delta)
{
    player_movement(&player->velocity, keybind, delta);
    player->position.x += player->velocity.x * delta;
    player->position.y += player->velocity.y * delta;
    player->collider.pos.x = player->position.x - player->collider.size.x / 2;
    player->collider.pos.y = player->position.y - player->collider.size.y / 2;
}


