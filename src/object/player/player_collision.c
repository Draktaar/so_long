/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:13:16 by achu              #+#    #+#             */
/*   Updated: 2025/04/16 01:31:08 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	check_ground(t_player *player, t_rect wall)
{
	if (!player->is_ground && is_collided(player->ground_col, wall))
	{
		player->is_ground = true;
	}
	else if (player->is_ground && !is_collided(player->ground_col,  wall))
	{
		player->is_ground = false;
	}
}

void	update_collision(t_player *player, t_rect solid)
{
	t_vec2	overlap;
	if (is_collided(player->collider, solid))
	{
		overlap = ft_penetration(player->collider, solid);
		if (overlap.x < overlap.y)
		{
			player->velocity.x = 0;
			player->position.x += overlap.x * (player->position.x < solid.pos.x ? -1 : 1);
		}
		else
		{
			player->velocity.y = 0;
			player->position.y += overlap.y * (player->position.y < solid.pos.y ? -1 : 1);
		}
	}
	player->collider.pos.x = player->position.x - player->collider.size.x / 2;
	player->collider.pos.y = player->position.y - player->collider.size.y / 2;
	player->ground_col.pos.x = player->collider.pos.x;
	player->ground_col.pos.y = player->collider.pos.y + player->collider.size.y - 3;
}
