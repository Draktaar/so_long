/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:03:52 by achu              #+#    #+#             */
/*   Updated: 2025/04/15 02:58:39 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/render.h"
#include "common.h"
#include "system.h"

void	render(t_system *sys)
{
	t_game	*game;

	game = sys->game;
	draw_clear(&sys->buffer, 0x505CB2);
	draw_bg(&sys->buffer);
	for (size_t i = 0; i < 314; i++)
	{
		for (int y = 0; y < game->solids[i].collider.size.y; y++) {
			for (int x = 0; x < game->solids[i].collider.size.y; x++) {
				unsigned int color = get_pixel(&game->solids[i].sprite.img, x, y);
				float alpha = 1.0f;
				if ((color & 0x00FFFFFF) != 0)
				{
					unsigned int faded = pixel_alpha(color, alpha);
					if (alpha > 0.0f)
						pixel_put(&sys->buffer, x + game->solids[i].collider.pos.x, y +game->solids[i].collider.pos.y, faded);
				}
			}
		}
	}
	for (size_t i = 0; i < 314; i++)
	{
		for (int y = 0; y < game->berries[i].collider.size.y; y++) {
			for (int x = 0; x < game->berries[i].collider.size.y; x++) {
				unsigned int color = get_pixel(&game->berries[i].sprite.img, x, y);
				float alpha = 1.0f;
				if ((color & 0x00FFFFFF) != 0)
				{
					unsigned int faded = pixel_alpha(color, alpha);
					if (alpha > 0.0f)
						pixel_put(&sys->buffer, x + game->berries[i].collider.pos.x, y +game->berries[i].collider.pos.y, faded);
				}
			}
		}		
	}
	for (size_t i = 0; i < 314; i++)
		draw_rect(&sys->buffer, game->solids[i].collider, RED);
	draw_rect(&sys->buffer, game->player.collider, WHITE);
	pixel_scale(&sys->buffer, &sys->scale, 4);
	mlx_put_image_to_window(sys->display.mlx, sys->display.win, sys->scale.ptr, 0, 0);
	mlx_do_sync(sys->display.mlx);
}
