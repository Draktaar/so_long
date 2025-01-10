/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:58:00 by achu              #+#    #+#             */
/*   Updated: 2025/01/10 16:27:17 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void	make_sprite(t_display display, t_sprite *sprite, char *filepath)
{
	sprite->img = mlx_xpm_file_to_image(display.mlx,
			filepath,
			&sprite->h, &sprite->w);
	sprite->addr = mlx_get_data_addr(sprite->img,
			&sprite->bits_per_pixel,
			&sprite->line_len,
			&sprite->endian);
}

void	init_sprite(t_game *game)
{
	make_sprite(game->display, &game->player.sprite, "./assets/xpm/player.xpm");
	make_sprite(game->display, &game->wall.sprite, "./assets/xpm/wall.xpm");
	make_sprite(game->display, &game->coin.sprite, "./assets/xpm/coin.xpm");
	make_sprite(game->display, &game->exit.sprite, "./assets/xpm/exit.xpm");
}
