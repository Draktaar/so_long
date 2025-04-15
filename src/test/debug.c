/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:43:50 by achu              #+#    #+#             */
/*   Updated: 2025/04/15 03:10:05 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/image.h"
#include "engine/render.h"
#include "engine/vec.h"

void	draw_bg(t_img *buffer)
{
	for (int y = 0; y < 180; y++)
		for (int x = 0; x < 320; x++)
			pixel_put(buffer, x, y, 0xFF505cb2);
}

// Draw the entire square into the screen
void	draw_square(t_img *image, t_rect rect, unsigned int color)
{
	int	y;
	int x;

	y = rect.pos.y;
	while (y < rect.pos.y + rect.size.y)
	{
		x = rect.pos.x;
		while (x < rect.pos.x + rect.size.x)
		{
			float alpha = 1.0f;
			if ((color & 0x00FFFFFF) != 0)
			{
				unsigned int faded = pixel_alpha(color, alpha);
				if (alpha > 0.0f)
					pixel_put(image, x, y, faded);
			}
			x++;
		}
		y++;
	}
}

// Draw the border of the rect into the screen
void	draw_rect(t_img *image, t_rect rect, unsigned int color)
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
			{
				float alpha = 1.0f;
				if ((color & 0x00FFFFFF) != 0)
				{
					unsigned int faded = pixel_alpha(color, alpha);
					if (alpha > 0.0f)
						pixel_put(image, x, y, faded);
				}
			}
			else if (x < rect.pos.x + 1 || x > rect.pos.x + rect.size.x - 2)
			{
				float alpha = 1.0f;
				if ((color & 0x00FFFFFF) != 0)
				{
					unsigned int faded = pixel_alpha(color, alpha);
					if (alpha > 0.0f)
						pixel_put(image, x, y, faded);
				}
			}
			x++;
		}
		y++;
	}
}
