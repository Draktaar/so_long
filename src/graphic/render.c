/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:03:52 by achu              #+#    #+#             */
/*   Updated: 2025/04/13 19:51:09 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/render.h"
#include "common.h"
#include "system.h"

void	render(t_system *sys)
{
	//mlx_clear_window(sys->display.mlx, sys->display.win);
	draw_bg(&sys->buffer);
	// for (size_t i = 0; i < 314; i++)
	// {
	// 	for (int y = 0; y < sys->solids[i].collider.size.y; y++) {
	// 		for (int x = 0; x < sys->solids[i].collider.size.y; x++) {
	// 			int color = get_pixel(&sys->solids[i].sprite.img, x, y);
	// 			ft_pixel_put(&sys->game, sys->solids[i].collider.pos.x + x,  sys->solids[i].collider.pos.y + y, color);
	// 		}
	// 	}
	// }
	for (size_t i = 0; i < 314; i++)
		draw_rect(&sys->buffer, sys->game->solids[i].collider, RED);
	draw_rect(&sys->buffer, sys->game->player.collider, WHITE);
	pixel_scale(&sys->buffer, &sys->scale, 4);
	mlx_put_image_to_window(sys->display.mlx, sys->display.win, sys->scale.ptr, 0, 0);
	mlx_do_sync(sys->display.mlx);
}
