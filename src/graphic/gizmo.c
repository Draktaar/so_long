/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gizmo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:21:57 by achu              #+#    #+#             */
/*   Updated: 2025/03/21 01:04:14 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
    char    *pixel;
    int		i;

    i = img->bpp - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
    while (i >= 0)
    {
        if (img->endian != 0)
            *pixel++ = (color >> i) & 0xFF;
        else
            *pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
        i -= 8;
    }
}

int draw_rect(t_display *data, t_rect rect, int color)
{
	int	y;
	int x;

	if (data->win == NULL)
		return (1);
	y = rect.pos.y;
	while (y < rect.pos.y + rect.size.y)
	{
		x = rect.pos.x;
		while (x < rect.pos.x + rect.size.x)
		{
			mlx_pixel_put(data->mlx, data->win, x, y, color);
			++x;
		}
		++y;
	}
	return (0);
}

int draw_rect_line(t_display *data, t_rect rect, int color)
{
	int	y;
	int x;

	if (data->win == NULL)
		return (1);
	y = rect.pos.y;
	while (y < rect.pos.y + rect.size.y)
	{
		x = rect.pos.x;
		while (x < rect.pos.x + rect.size.x)
		{
			if (y < rect.pos.y + 2 || y > rect.pos.y + rect.size.y - 2)
				mlx_pixel_put(data->mlx, data->win, x, y, color);
			else if (x < rect.pos.x + 2 || x > rect.pos.x + rect.size.x - 2)
				mlx_pixel_put(data->mlx, data->win, x, y, color);
			++x;
		}
		++y;
	}
	return (0);
}
