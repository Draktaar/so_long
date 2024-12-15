/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:47:42 by achu              #+#    #+#             */
/*   Updated: 2024/12/15 18:38:56 by achu             ###   ########.fr       */
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
	if (key == A)
		game->player.pos.x -= 10;
	else if (key == S)
		game->player.pos.y += 10;
	else if (key == D)
		game->player.pos.x += 10;
	else if (key == W)
		game->player.pos.y -= 10;
	else if (key == ESC)	
        mlx_destroy_window(game->display.mlx, game->display.win);
	return (0);
}
