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

// Copy pixel from an image to another image
void	ft_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || y < 0 || x >= img->w || y >= img->h)
		return ;
	pixel = img->addr + (y * img->llen + x * (img->bpp / 8));
	*(unsigned int*)pixel = color;
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

// Scale the pixel from an image to another image
void	pixel_scale(t_img *src, t_img *dst, int scale)
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
