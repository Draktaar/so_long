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

void	ft_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->llen + x * (img->bpp / 8));
	*(unsigned int*)pixel = color;
}

void	draw_square(t_display window, t_rect rect, int color)
{
	t_img	image;
	int	y;
	int x;

	image = new_img(window, rect.size.x, rect.size.y);
	y = rect.pos.y;
	while (y < rect.size.y)
	{
		x = rect.pos.x;
		while (x < rect.size.x)
		{
			ft_pixel_put(&image, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(window.mlx, window.win, image.ptr, rect.pos.x, rect.pos.y);
}

void	draw_box(t_display window, t_rect rect, int color)
{
	t_img	image;
	int	y;
	int x;

	image = new_img(window, rect.size.x, rect.size.y);
	y = 0;
	while (y <= rect.size.y)
	{
		x = 0;
		while (x <= rect.size.x)
		{
			if (y < 4 || y > rect.size.y - 2)
				ft_pixel_put(&image, x, y, color);
			else if (x < 2 || x > rect.size.x - 2)
				ft_pixel_put(&image, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(window.mlx, window.win, image.ptr, rect.pos.x, rect.pos.y);
}
