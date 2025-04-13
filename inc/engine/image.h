/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:23:26 by achu              #+#    #+#             */
/*   Updated: 2025/04/11 15:51:23 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include <stdint.h>
# include "window.h"

# define IMG_WALL	"sprites/wall.xpm"

typedef struct s_img
{
	t_display	screen;
	void		*ptr;
	char		*addr;
	int			h;
	int			w;
	int			bpp;
	int			llen;
	int			endian;
}	t_img;

typedef struct s_sprite
{
	t_img	img;
}	t_sprite;

t_img		new_xpm(t_display window, char *file);
t_img		new_img(t_display window, int h, int w);

void		pixel_scale(t_img *src, t_img *dst, int scale);
void		ft_pixel_put(t_img *img, int x, int y, int color);
uint32_t	get_pixel(t_img *img, int x, int y);

#endif