/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gizmo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:57:53 by achu              #+#    #+#             */
/*   Updated: 2024/12/17 12:58:21 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sprite.h"
#include "../includes/so_long.h"

void	draw_pixel(t_sprite *data, int x, int y, int color)
{
	char	*pxl;

	pxl = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)pxl = color;
}

void	gizmo_rect(t_rect rect, t_sprite *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < rect.size_h)
	{
		x = 0;
		while (x < rect.size_w)
		{
			draw_pixel(data, x + rect.x, y + rect.y, rect.color);
			x++;
		}
		y++;
	}
}