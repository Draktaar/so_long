/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:13:16 by achu              #+#    #+#             */
/*   Updated: 2025/04/22 15:37:27 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "player.h"

static bool	is_solid(t_solid *solids, t_rect player)
{
	uint32_t	i;

	i = 0;
	while (i < 314)
	{
		if (is_collided(player, solids[i].collider))
			return (true);
		i++;
	}
	return (false);
}

static int	ft_sign(int x)
{
	return ((x > 0) - (x < 0));
}

static void	move_x(float *remainder, float vel,
	t_player *player, t_solid *solid)
{
	int		move;
	int		sign;
	t_rect	col;

	col = player->collider;
	*remainder += vel;
	move = (int)roundf(*remainder);
	if (move != 0)
	{
		*remainder -= move;
		sign = ft_sign(move);
		while (move != 0)
		{
			col.pos.x += sign;
			if (!is_solid(solid, col))
			{
				player->position.x += sign;
				player->collider.pos.x = player->position.x;
				player->ground_col.pos.x = player->collider.pos.x;
				move -= sign;
			}
			else
			{
				player->velocity.x = 0;
				break ;
			}
		}
	}
}

static void	move_y(float *remainder, float vel,
	t_player *player, t_solid *solid)
{
	int		move;
	int		sign;
	t_rect	col;

	*remainder += vel;
	move = (int)roundf(*remainder);
	if (move != 0)
	{
		*remainder -= move;
		sign = ft_sign(move);
		while (move != 0)
		{
			col = player->collider;
			col.pos.y += sign;
			if (!is_solid(solid, col))
			{
				player->position.y += sign;
				player->collider.pos.y = player->position.y;
				player->ground_col.pos.y = player->collider.pos.y
					+ player->collider.size.y - 3;
				move -= sign;
			}
			else
			{
				player->velocity.y = 0;
				break ;
			}
		}
	}
}

void	update_collision(t_player *player, t_solid *solids, double delta)
{
	move_x(&player->remainder.x, player->velocity.x * delta, player, solids);
	move_y(&player->remainder.y, player->velocity.y * delta, player, solids);
}
