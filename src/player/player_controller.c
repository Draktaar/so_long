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

void    player_movement(t_rect *player, t_input *keybind, double delta)
{
    if (keybind[MOVE_UP].hold)
        player->pos.y -= ACCELERATION * delta;
    if (keybind[MOVE_DOWN].hold)
        player->pos.y += ACCELERATION * delta;
    if (keybind[MOVE_LEFT].hold)
        player->pos.x -= ACCELERATION * delta;
    if (keybind[MOVE_RIGHT].hold)
        player->pos.x += ACCELERATION * delta;
}
