/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:07:47 by achu              #+#    #+#             */
/*   Updated: 2024/12/20 16:32:53 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_player(t_game *game, t_vector2 next)
{
	if ((*game).map[next.y][next.x] != WALL)
		game->player.pos = next;
	if ((*game).map[next.y][next.x] != COLLECTIBLE)
		(game->map[next.y][next.x] == '0', \
		game->collect++);
}
