/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:03:52 by achu              #+#    #+#             */
/*   Updated: 2025/04/18 16:51:08 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/render.h"
#include "object/object.h"
#include "common.h"
#include "system.h"

static void	render_bg(t_img *buffer, t_img *bg, float alpha)
{
	uint32_t	color;
	uint32_t	faded;
	int			x;
	int			y;

	y = 0;
	if (alpha < 0.0f)
		return ;
	while (y < bg->h)
	{
		x = 0;
		while (x < bg->w)
		{
			color = get_pixel(bg, x, y);
			if ((color & 0x00FFFFFF) != 0)
			{
				faded = pixel_alpha(color, alpha);
				pixel_put(buffer, x, y, faded);
			}
			x++;
		}
		y++;
	}
}

static void	render_solid(t_img *buffer, t_solid solid, float alpha)
{
	uint32_t	color;
	uint32_t	faded;
	int			x;
	int			y;

	y = 0;
	if (alpha < 0.0f)
		return ;
	while (y < solid.sprite.img.h)
	{
		x = 0;
		while (x < solid.sprite.img.w)
		{
			color = get_pixel(&solid.sprite.img, x, y);
			if ((color & 0x00FFFFFF) != 0)
			{
				faded = pixel_alpha(color, alpha);
				pixel_put(buffer, x + solid.collider.pos.x, y + solid.collider.pos.y, faded);
			}
			x++;
		}
		y++;
	}
}

static void	render_berry(t_img *buffer, t_berry strawberry, float alpha)
{
	uint32_t	color;
	uint32_t	faded;
	int			x;
	int			y;

	y = 0;
	if (alpha < 0.0f)
		return ;
	while (y < strawberry.sprite.img.h)
	{
		x = 0;
		while (x < strawberry.sprite.img.w)
		{
			color = get_pixel(&strawberry.sprite.img, x, y);
			if ((color & 0x00FFFFFF) != 0)
			{
				faded = pixel_alpha(color, alpha);
				pixel_put(buffer, x + strawberry.collider.pos.x, y + strawberry.collider.pos.y, faded);
			}
			x++;
		}
		y++;
	}
}

static void	render_heart(t_img *buffer, t_heart heart, float alpha)
{
	uint32_t	color;
	uint32_t	faded;
	int			x;
	int			y;

	y = 0;
	if (alpha < 0.0f)
		return ;
	while (y < heart.sprite.img.h)
	{
		x = 0;
		while (x < heart.sprite.img.w)
		{
			color = get_pixel(&heart.sprite.img, x, y);
			if ((color & 0x00FFFFFF) != 0)
			{
				faded = pixel_alpha(color, alpha);
				pixel_put(buffer, x + heart.collider.pos.x - 4, y + heart.collider.pos.y - 4, faded);
			}
			x++;
		}
		y++;
	}
}

void	render(t_system *sys)
{
	t_game	*game;

	game = sys->game;
	clear_buffer(&sys->buffer, 0x505CB2);
	draw_bg(&sys->buffer);
	render_bg(&sys->buffer, &sys->game->bg0, 1.0f);
	render_bg(&sys->buffer, &sys->game->bg1, 1.0f);
	for (size_t i = 0; i < sys->game->solid_size; i++)
		render_solid(&sys->buffer, sys->game->solids[i], 1.0f);
	for (size_t i = 0; i < sys->game->berry_size; i++)
		render_berry(&sys->buffer, sys->game->berries[i], 1.0f);
	render_heart(&sys->buffer, game->heart, 1.0f);
	//DEBUG
	for (size_t i = 0; i < sys->game->solid_size; i++)
		draw_rect(&sys->buffer, game->solids[i].collider, RED);
	for (size_t i = 0; i < sys->game->berry_size; i++)
		draw_rect(&sys->buffer, game->berries[i].collider, RED);
	draw_rect(&sys->buffer, game->heart.collider, RED);
	draw_rect(&sys->buffer, game->player.collider, WHITE);
	draw_rect(&sys->buffer, game->player.ground_col, RED);
	pixel_scale(&sys->buffer, &sys->scale, 4);
	mlx_put_image_to_window(sys->window.mlx, sys->window.win, sys->scale.ptr, 0, 0);
	mlx_do_sync(sys->window.mlx);
}
