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

#include "engine/image.h"
#include "common.h"

t_img	new_xpm(t_display window, char *file)
{
	t_img image;

	image.w = 0;
	image.h = 0;
	image.ptr = mlx_xpm_file_to_image(window.mlx, file, &image.w, &image.h);
	if (!image.ptr)
		ft_perror("Error: Image could not be read");
	image.addr = mlx_get_data_addr(image.ptr,
		&(image.bpp), &(image.llen), &(image.endian));
	image.screen = window;
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
	image.addr = mlx_get_data_addr(image.ptr,
		&(image.bpp), &(image.llen), &(image.endian));
	image.screen = window;
	return (image);
}

void	destroy_img(t_img image)
{
	if (image.ptr && image.screen.mlx) 
		mlx_destroy_image(image.screen.mlx, image.ptr);
}
