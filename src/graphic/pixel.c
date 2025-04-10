/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:21:57 by achu              #+#    #+#             */
/*   Updated: 2025/04/09 22:35:23 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// Put image to another image
void	ft_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || y < 0 || x >= img->w || y >= img->h)
		return ;
	pixel = img->addr + (y * img->llen + x * (img->bpp / 8));
	*(unsigned int*)pixel = color;
}

unsigned int	get_pixel(t_img *img, int x, int y)
{
	char	*pixel;

	if (x < 0 || y < 0 || x >= img->w || y >= img->h)
		return (0);
	pixel = img->addr + (y * img->llen + x * (img->bpp / 8));
	return (*(unsigned int *)pixel);
}

void	draw_bg(t_img *game)
{
	for (int y = 0; y < 180; y++)
		for (int x = 0; x < 320; x++)
			ft_pixel_put(game, x, y, 0x505cb2);
}

void	blit_scaled(t_img *src, t_img *dst, int scale)
{
	int	x, y, dx, dy;
	unsigned int	color;

	for (y = 0; y < src->h; y++)
	{
		for (x = 0; x < src->w; x++)
		{
			color = get_pixel(src, x, y);
			for (dy = 0; dy < scale; dy++)
				for (dx = 0; dx < scale; dx++)
					ft_pixel_put(dst, x * scale + dx, y * scale + dy, color);
		}
	}
}

// Draw the entire square into the screen
void	draw_square(t_img *image, t_rect rect, int color)
{
	int	y;
	int x;

	y = rect.pos.y;
	while (y <= rect.pos.y + rect.size.y)
	{
		x = rect.pos.x;
		while (x <= rect.pos.x + rect.size.x)
		{
			ft_pixel_put(image, x, y, color);
			x++;
		}
		y++;
	}
}

// Draw the border of the rect into the screen
void	draw_rect(t_img *image, t_rect rect, int color)
{
	int	y;
	int x;

	y = rect.pos.y;
	while (y <= rect.pos.y + rect.size.y)
	{
		x = rect.pos.x;
		while (x <= rect.pos.x + rect.size.x)
		{
			if (y < rect.pos.y + 1 || y > rect.pos.y + rect.size.y - 1)
				ft_pixel_put(image, x, y, color);
			else if (x < rect.pos.x + 1 || x > rect.pos.x + rect.size.x - 1)
				ft_pixel_put(image, x, y, color);
			x++;
		}
		y++;
	}
}
