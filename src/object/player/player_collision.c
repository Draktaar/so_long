/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:13:16 by achu              #+#    #+#             */
/*   Updated: 2025/04/10 15:39:24 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	check_ground(t_player *player, t_solid wall)
{
	if (!player->is_ground && is_collided(player->ground_col, wall.collider))
	{
		player->is_ground = true;
	}
	else if (player->is_ground && !is_collided(player->ground_col,  wall.collider))
	{
		player->is_ground = false;
	}
}

void	update_collision(t_player *player, t_solid solid)
{
	t_vec2	overlap;
	if (is_collided(player->col, solid.collider))
	{
		overlap = ft_penetration(player->col, solid.collider);
		if (overlap.x < overlap.y)
		{
			player->vel.x = 0;
			player->pos.x += overlap.x * (player->pos.x < solid.collider.pos.x ? -1 : 1);
		}
		else
		{
			player->vel.y = 0;
			player->pos.y += overlap.y * (player->pos.y < solid.collider.pos.y ? -1 : 1);
		}
	}
}
