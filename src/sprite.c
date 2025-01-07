/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:58:00 by achu              #+#    #+#             */
/*   Updated: 2025/01/07 15:52:06 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void	make_image(t_display display, t_sprite *sprite, char *filepath)
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
	make_image(game->display, &game->player.sprite, "./assets/xpm/player.xpm");
	make_image(game->display, &game->wall.sprite, "./assets/xpm/wall.xpm");
	make_image(game->display, &game->coin.sprite, "./assets/xpm/coin.xpm");
	make_image(game->display, &game->exit.sprite, "./assets/xpm/exit.xpm");
}
