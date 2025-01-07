/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:07:47 by achu              #+#    #+#             */
/*   Updated: 2025/01/07 10:31:35 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	move_player(t_game *game, t_vector2 next)
{
	if ((*game).map[next.y][next.x] != WALL)
		game->player.pos = next;
	if ((*game).map[next.y][next.x] != COIN)
		(game->map[next.y][next.x] == '0', \
		game->collect++);
}
