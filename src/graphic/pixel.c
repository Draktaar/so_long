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

#include "engine/image.h"

// Copy pixel from an image to another image
void	put_pixel(t_img *img, int x, int y, unsigned int color)
{
	char	*pixel;

	if (x < 0 || y < 0 || x >= img->w || y >= img->h)
		return ;
	pixel = img->addr + (y * img->llen + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

// Get the pixel color RGBA
unsigned int	get_pixel(t_img *img, int x, int y)
{
	char	*pixel;

	if (x < 0 || y < 0 || x >= img->w || y >= img->h)
		return (0);
	pixel = img->addr + (y * img->llen + x * (img->bpp / 8));
	return (*(unsigned int *)pixel);
}

unsigned int	pixel_alpha(int color, float alpha)
{
	return ((int)(alpha * 255) << 24 | color);
}

// Scale the pixel from an image to another image
void	pixel_scale(t_img *old, t_img *new, int scale)
{
	int	x;
	int	y;
	int	scaled_x;
	int	scaled_y;

	if (scale < 0)
		return ;
	scaled_x = old->w * scale;
	scaled_y = old->h * scale;
	y = 0;
	while (y < scaled_y)
	{
		x = 0;
		while (x < scaled_x)
		{
			put_pixel(new, x, y, get_pixel(old, x / scale, y / scale));
			x++;
		}
		y++;
	}
}

void	clear_buffer(t_img *buffer, unsigned int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < buffer->h)
	{
		x = 0;
		while (x < buffer->w)
		{
			put_pixel(buffer, x, y, color | 0xFF000000);
			x++;
		}
		y++;
	}
}
