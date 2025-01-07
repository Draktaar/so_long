/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:58:00 by achu              #+#    #+#             */
/*   Updated: 2024/12/20 17:06:00 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	create_image(t_display display, t_sprite *sprite, char *filepath)
{
	sprite->img = mlx_xpm_file_to_image(display.mlx,
			filepath,
			&sprite->h, &sprite->w);
	sprite->addr = mlx_get_data_addr(sprite->img,
			&sprite->bits_per_pixel,
			&sprite->line_length,
			&sprite->endian);
}

void	init_img(t_game *game)
{
	create_image(game->display, &game->player.sprite, "./assets/xpm/player.xpm");
	create_image(game->display, &game->wall.sprite, "./assets/xpm/wall.xpm");
	create_image(game->display, &game->coin.sprite, "./assets/xpm/coin.xpm");
	create_image(game->display, &game->exit.sprite, "./assets/xpm/exit.xpm");
}
