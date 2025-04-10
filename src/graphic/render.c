/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:03:52 by achu              #+#    #+#             */
/*   Updated: 2025/04/10 16:45:36 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	render(t_system *game)
{
	//mlx_clear_window(manager->display.mlx, manager->display.win);
	draw_bg(&game->game);
	for (size_t i = 0; i < 63; i++)
	{
		//mlx_put_image_to_window(manager->display.mlx, manager->display.win, manager->solids[i].sprite.img.ptr, manager->solids[i].collider.pos.x, manager->solids[i].collider.pos.y);
		for (int y = 0; y < game->solids[i].collider.size.y; y++) {
			for (int x = 0; x < game->solids[i].collider.size.y; x++) {
				int color = get_pixel(&game->solids[i].sprite.img, x, y);
				ft_pixel_put(&game->game, game->solids[i].collider.pos.x + x,  game->solids[i].collider.pos.y + y, color);
			}
		}
	}
	for (size_t i = 0; i < 63; i++)
		draw_rect(&game->game, game->solids[i].collider, RED);
	draw_rect(&game->game, game->player.collider, WHITE);
	pixel_scale(&game->game, &game->screen, 4);
	mlx_put_image_to_window(game->display.mlx, game->display.win, game->screen.ptr, 0, 0);
	mlx_do_sync(game->display.mlx);
}
