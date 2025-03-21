/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:13:16 by achu              #+#    #+#             */
/*   Updated: 2025/03/21 17:07:40 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

double	ft_abs(double val)
{
	if (val < 0)
        return -val;
    else
        return val;
}

double	ft_min(double a, double b)
{
	if (a < b)
        return a;
    else
        return b;
}

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

t_rect	ft_minkowski_diff(t_rect a, t_rect b)
{
	t_rect	diff;

	diff.pos.x = a.pos.x - (b.pos.x + b.size.x);
	diff.pos.y = a.pos.y - (b.pos.y + b.size.y);
	diff.size.x = a.size.x + b.size.x;
	diff.size.y = a.size.y + b.size.y;
	return (diff);
}

bool	is_physics_collided(t_rect diff)
{
	t_vec2	origin;

	origin.x = 0;
	origin.y = 0;
	return (is_point_in_rect(origin, diff));
}

t_vec2	test(t_rect diff)
{
	t_vec2	overlap;

	overlap.x = ft_min(diff.pos.x + diff.size.x, -diff.pos.x);
	overlap.y = ft_min(diff.pos.y + diff.size.y, -diff.pos.y);
	return (overlap);
}

t_vec2	ooverlap(t_rect a, t_rect b)
{
	t_vec2	overlap;

	overlap.x = ft_min(ft_abs(a.pos.x + a.size.x - b.pos.x), ft_abs(b.pos.x + b.size.x - a.pos.x));
	overlap.y = ft_min(ft_abs(a.pos.y + a.size.y - b.pos.y), ft_abs(b.pos.y + b.size.y - a.pos.y));
	return (overlap);
}

void	update_horizontal(t_player *player, t_rect wall)
{
	t_vec2	overlap;

	if (is_collided(player->collider, wall))
	{
		overlap = ooverlap(player->collider, wall);
        if (overlap.x < overlap.y)
            //player->collider.pos.x += overlap.x * (player->collider.pos.x < wall.pos.x ? -1 : 1);
			player->velocity.x = overlap.x * (player->position.x < wall.pos.x ? -1 : 1);
        else
			//player->collider.pos.y += overlap.y * (player->collider.pos.y < wall.pos.y ? -1 : 1);
            player->velocity.y = overlap.y * (player->position.y < wall.pos.y ? -1 : 1);
	}
}

void	update_vertical(t_player player, t_rect wall)
{
	
}
