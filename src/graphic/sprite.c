/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:30:40 by achu              #+#    #+#             */
/*   Updated: 2025/03/26 19:10:20 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_img	new_img(char *file, t_display window)
{
	t_img image;

	image.img = mlx_xpm_file_to_image(window.mlx, file, &image.w, &image.h);
	if (!image.img)
		ft_fprintf(STDERR_FILENO, "Image could not be read\n");
	image.addr = mlx_get_data_addr(image.img, &(image.bpp),
		&(image.line_len), &(image.endian));
	return (image);
}

void	destroy_img(t_img image)
{
	if (image.img && image.win.mlx) 
       mlx_destroy_image(image.win.mlx, image.img);
}
