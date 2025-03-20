/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gizmo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:21:57 by achu              #+#    #+#             */
/*   Updated: 2025/03/20 23:30:32 by achu             ###   ########.fr       */
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

int draw_rect(t_display *data, t_rect rect)
{
    int	i;
    int j;

    if (data->win == NULL)
        return (1);
    i = rect.pos.y - (rect.size.y / 2);
    while (i < rect.pos.y + rect.size.y)
    {
        j = rect.pos.x - (rect.size.x / 2);
        while (j < rect.pos.x + rect.size.x)
            mlx_pixel_put(data->mlx, data->win, j++, i, RED_PIXEL);
        ++i;
    }
    return (0);
}