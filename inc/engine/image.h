/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:23:26 by achu              #+#    #+#             */
/*   Updated: 2025/04/15 19:18:39 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include <stdint.h>
# include "window.h"

# define PIXEL_SIZE	8
# define IMG_BG0	"assets/bg/bg0.xpm"
# define IMG_BG		"assets/bg/bg1.xpm"
# define IMG_WALL	"assets/wall.xpm"
# define IMG_BERRY	"assets/strawberry.xpm"

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

t_img			new_xpm(t_display window, char *file);
t_img			new_img(t_display window, int h, int w);
t_img			new_img_alpha(t_display window, int w, int h);

void			pixel_scale(t_img *src, t_img *dst, int scale);
void			pixel_put(t_img *img, int x, int y, unsigned int color);
unsigned int	pixel_alpha(int color, float alpha);
uint32_t		get_pixel(t_img *img, int x, int y);
void 			draw_clear(t_img *buffer, unsigned int color);


#endif