/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:47:42 by achu              #+#    #+#             */
/*   Updated: 2024/12/17 16:05:48 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_manager *game)
{
    mlx_destroy_window(game->display.mlx, game->display.win);
    return (0);
}

int	input(int key, t_manager *game)
{
	t_vector2	pos;
	
	pos = game->player.pos;
	if (key == W)
		move(game, pos.x, pos.y - 1);
		//game->player.pos.y--;
	else if (key == A)
		move(game, pos.x - 1, pos.y);
		//game->player.pos.x--;
	else if (key == S)
		move(game, pos.x, pos.y + 1);
		//game->player.pos.y++;
	else if (key == D)
		move(game, pos.x + 1, pos.y);
		//game->player.pos.x++;
	else if (key == ESC)	
        mlx_destroy_window(game->display.mlx, game->display.win);
	return (0);
}
