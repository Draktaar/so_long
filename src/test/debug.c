/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:43:50 by achu              #+#    #+#             */
/*   Updated: 2025/04/13 16:26:21 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/image.h"
#include "engine/render.h"
#include "engine/vec.h"

void	draw_bg(t_img *buffer)
{
	for (int y = 0; y < 180; y++)
		for (int x = 0; x < 320; x++)
			ft_pixel_put(buffer, x, y, 0x505cb2);
}

// Draw the entire square into the screen
void	draw_square(t_img *image, t_rect rect, int color)
{
	int	y;
	int x;

	y = rect.pos.y;
	while (y < rect.pos.y + rect.size.y)
	{
		x = rect.pos.x;
		while (x < rect.pos.x + rect.size.x)
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
	while (y < rect.pos.y + rect.size.y)
	{
		x = rect.pos.x;
		while (x < rect.pos.x + rect.size.x)
		{
			if (y < rect.pos.y + 1 || y > rect.pos.y + rect.size.y - 2)
				ft_pixel_put(image, x, y, color);
			else if (x < rect.pos.x + 1 || x > rect.pos.x + rect.size.x - 2)
				ft_pixel_put(image, x, y, color);
			x++;
		}
		y++;
	}
}
