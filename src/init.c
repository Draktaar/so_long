/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:49:25 by achu              #+#    #+#             */
/*   Updated: 2024/12/17 12:35:55 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_manager *game)
{
	game->display.mlx = mlx_init();
	game->display.win = mlx_new_window(game->display.mlx,
			game->display.width, game->display.height, "so_long");
}
