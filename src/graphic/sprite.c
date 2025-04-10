/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:30:40 by achu              #+#    #+#             */
/*   Updated: 2025/04/09 22:27:40 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_img	new_xpm(t_display window, char *file)
{
	t_img image;

	image.w = 0;
	image.h = 0;
	image.ptr = mlx_xpm_file_to_image(window.mlx, file, &image.w, &image.h);
	if (!image.ptr)
		ft_perror("Error: Image could not be read");
	image.addr = mlx_get_data_addr(image.ptr, &(image.bpp),
		&(image.llen), &(image.endian));
	return (image);
}

t_img	new_img(t_display window, int w, int h)
{
	t_img image;

	image.w = w;
	image.h = h;
	image.ptr = mlx_new_image(window.mlx, w, h);
	if (!image.ptr)
		ft_perror("Error: Failed to create image");
	image.addr = mlx_get_data_addr(image.ptr, &(image.bpp),
		&(image.llen), &(image.endian));
	return (image);
}

void	put_img(t_display window, t_img image)
{
	mlx_put_image_to_window(window.mlx, window.win, image.ptr, 50, 50);
}

void	destroy_img(t_img image)
{
	if (image.ptr && image.window.mlx) 
       mlx_destroy_image(image.window.mlx, image.ptr);
}
