/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:29:48 by achu              #+#    #+#             */
/*   Updated: 2025/01/07 14:37:57 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game.h"

int init_setup(t_game *game, int argc, char **argv);

int	update(void *ptr)
{
	t_game	*game;
	
	game = (t_game *)ptr;
	mlx_clear_window(game->display.mlx, game->display.win);
	int	y = 0;
	while (game->map[y])
	{
		int x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == WALL)
				mlx_put_image_to_window(game->display.mlx, game->display.win, game->wall.sprite.img, x * 64, y * 64);
			else if (game->map[y][x] == PLAYER)
				mlx_put_image_to_window(game->display.mlx, game->display.win, game->player.sprite.img, game->player.pos.x * 64, game->player.pos.y * 64);
			else if (game->map[y][x] == COIN)
				mlx_put_image_to_window(game->display.mlx, game->display.win, game->coin.sprite.img, x * 64, y * 64);
			x++;
		}
		y++;
	}
	return (0);
}

#include "libft.h"
#include "../includes/map.h"
#include "../includes/game.h"

int	update(void *ptr);

// float ease_in(float t)
// {
// 	return (t * t);
// }
// static float ease_out(float t)
// {
// 	return 1 - (1 - t) * (1 - t);
// }

// float	lerp(float start, float end, float t)
// {
// 	return (start + ((end - start) * t));
// }

// int main(int argc, char const **argv)
// {
// 	t_game	game;

// 	if (!init_setup(&game, argc, argv))
// 		return (0);
// 	return (0);
// }


	if (!init_setup(&manager, argc, argv))
		return (0);
	start(&manager);
	return (1);
}
