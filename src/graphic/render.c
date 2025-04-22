/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:03:52 by achu              #+#    #+#             */
/*   Updated: 2025/04/22 03:28:54 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/render.h"
#include "engine/image.h"
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
	while (y < PIXEL_SIZE)
	{
		x = 0;
		while (x < PIXEL_SIZE)
		{
			color = get_pixel(&solid.sprite.img, x, y);
			if ((color & 0x00FFFFFF) != 0)
			{
				faded = pixel_alpha(color, alpha);
				pixel_put(buffer, x + solid.pos.x, y + solid.pos.y, faded);
			}
			x++;
		}
		y++;
	}
}

static void	render_spike(t_img *buffer, t_spike spike, float alpha)
{
	uint32_t	color;
	uint32_t	faded;
	int			x;
	int			y;

	y = 0;
	if (alpha < 0.0f)
		return ;
	while (y < PIXEL_SIZE)
	{
		x = 0;
		while (x < PIXEL_SIZE)
		{
			color = get_pixel(&spike.sprite.img, x , y);
			if ((color & 0x00FFFFFF) != 0)
			{
				faded = pixel_alpha(color, alpha);
				pixel_put(buffer, x + spike.pos.x, y + spike.pos.y, faded);
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
	if (strawberry.is_collected)
		return ;
	if (alpha < 0.0f)
		return ;
	while (y < PIXEL_SIZE * 2)
	{
		x = 0;
		while (x < PIXEL_SIZE * 2)
		{
			color = get_pixel(&strawberry.sprite.img, x + (strawberry.sprite.anim.current_frame * 16), y);
			if ((color & 0x00FFFFFF) != 0)
			{
				faded = pixel_alpha(color, alpha);
				pixel_put(buffer, x + strawberry.pos.x, y + strawberry.pos.y, faded);
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
	while (y < PIXEL_SIZE * 2 + 4)
	{
		x = 0;
		while (x < PIXEL_SIZE * 2 + 4)
		{
			color = get_pixel(&heart.sprite.img, x + (heart.sprite.anim.current_frame * 20), y);
			if ((color & 0x00FFFFFF) != 0)
			{
				faded = pixel_alpha(color, alpha);
				pixel_put(buffer, x + heart.pos.x - 2, y + heart.pos.y - 2, faded);
			}
			x++;
		}
		y++;
	}
}

static void	frame_anim(t_system *sys)
{
	uint32_t	i;

	i = 0;
	while (i < sys->game->berry_count)
	{
		update_frame(&sys->game->berries[i].sprite.anim, sys->delta);
		i++;
	}
	if (sys->game->heart.is_opened)
		update_frame(&sys->game->heart.sprite.anim, sys->delta);
}

static void	debug(t_system *sys)
{
	t_game	*game;

	game = sys->game;
	// for (size_t i = 0; i < game->solid_count; i++)
	// 	draw_rect(&sys->buffer, game->solids[i].collider, RED);
	// for (size_t i = 0; i < game->berry_count; i++)
	// 	draw_rect(&sys->buffer, game->berries[i].collider, RED);
	// for (size_t i = 0; i < game->spike_count; i++)
	// 	draw_rect(&sys->buffer, game->spikes[i].collider, RED);
	// draw_rect(&sys->buffer, game->heart.collider, RED);
	draw_rect(&sys->buffer, game->player.collider, WHITE);
	draw_rect(&sys->buffer, game->player.ground_col, RED);
}

static char	*timer(t_game *game)
{
	char	*str;
	double	time;
	int		min;
	int		sec;

	str = (char *)malloc(6 * sizeof(char));
	if (!str)
		return (NULL);
	time = game->timer_elapsed - game->timer_start;
	min = (int)time / 60;
	sec = (int)time % 60;
	str[0] = '0' + min / 10;
	str[1] = '0' + min % 10;
	str[2] = ':';
	str[3] = '0' + sec / 10;
	str[4] = '0' + sec % 10;
	str[5] = '\0';
	return (str);
}

void	render(t_system *sys)
{
	t_game	*game;
	char	*time;

	game = sys->game;
	time = timer(game);
	clear_buffer(&sys->buffer, 0x505CB2);
	draw_bg(&sys->buffer);
	frame_anim(sys);
	render_bg(&sys->buffer, &game->bg0, 1.0f);
	render_bg(&sys->buffer, &game->bg1, 1.0f);
	if (sys->game->heart.is_opened)
		render_heart(&sys->buffer, game->heart, 1.0f);
	for (size_t i = 0; i < game->berry_count; i++)
		render_berry(&sys->buffer, game->berries[i], 1.0f);
	for (size_t i = 0; i < sys->game->solid_count; i++)
		render_solid(&sys->buffer, game->solids[i], 1.0f);
	for (size_t i = 0; i < sys->game->spike_count; i++)
		render_spike(&sys->buffer, game->spikes[i], 1.0f);
	debug(sys);
	pixel_scale(&sys->buffer, &sys->scale, 4);
	mlx_put_image_to_window(sys->window.mlx, sys->window.win, sys->scale.ptr, 0, 0);
	mlx_string_put(sys->window.mlx, sys->window.win, game->player.position.x * 4 + 2, game->player.position.y * 4 - 15, WHITE, time);
	mlx_do_sync(sys->window.mlx);
}
