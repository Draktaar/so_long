/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:13:16 by achu              #+#    #+#             */
/*   Updated: 2025/03/25 17:30:52 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

bool	is_point_in_rect(t_vec2 point, t_rect rect)
{
	return (point.x >= rect.pos.x
		&& point.x <= rect.pos.x + rect.size.x
		&& point.y >= rect.pos.y
		&& point.y <= rect.pos.y + rect.size.y);
}

bool	is_collided(t_rect a, t_rect b)
{
	return (a.pos.x < b.pos.x + b.size.x
		&& a.pos.x + a.size.x > b.pos.x
		&& a.pos.y < b.pos.y + b.size.y
		&& a.pos.y + a.size.y > b.pos.y);
}

t_vec2	ft_penetration(t_rect a, t_rect b)
{
	t_vec2	overlap;

	overlap.x = fmin(fabs(a.pos.x + a.size.x - b.pos.x), fabs(b.pos.x + b.size.x - a.pos.x));
	overlap.y = fmin(fabs(a.pos.y + a.size.y - b.pos.y), fabs(b.pos.y + b.size.y - a.pos.y));
	return (overlap);
}

void	check_collision(t_player *player, t_rect wall)
{
	if (!player->is_ground && is_collided(player->ground_col, wall))
	{
		player->is_ground = true;
	}
	else if (player->is_ground && !is_collided(player->ground_col, wall))
	{
		player->is_ground = false;
	}
}

void	update_collision(t_player *player, t_rect wall)
{
	t_vec2	overlap;

	if (is_collided(player->collider, wall))
	{
		overlap = ft_penetration(player->collider, wall);
        if (overlap.x < overlap.y)
		{
			player->velocity.x = 0;
			player->position.x += overlap.x * (player->position.x < wall.pos.x ? -1 : 1);
		}
        else
		{
			player->velocity.y = 0;
			player->position.y += overlap.y * (player->position.y < wall.pos.y ? -1 : 1);
		}
	}
}
