/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:01:40 by achu              #+#    #+#             */
/*   Updated: 2025/01/10 16:06:44 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../includes/game.h"

t_display	setup_display(t_map *manager)
{
	t_display	display;

	display.height = (*manager).height;
	display.width = (*manager).width;
	display.mlx = mlx_init();
	display.win = mlx_new_window(display.mlx,
			display.width * 64, display.height * 64, "so_long");
	return (display);
}

t_game	init_gamemanager(t_map *manager)
{
	t_game	temp;

	temp.display = setup_display(manager);
	temp.map = (*manager).map;

	init_sprite(&temp);
	temp.exit.is_open = 0;

	temp.step = 0;
	temp.score = 0;
	temp.coins = (*manager).max_coin;
	return (temp);
}

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
			else if (game->map[y][x] == EXIT)
				mlx_put_image_to_window(game->display.mlx, game->display.win, game->exit.sprite.img, x * 64, y * 64);
			x++;
		}
		y++;
	}
	return (0);
}

int	start(t_map *map)
{
	t_game	game;
	
	game = init_gamemanager(map);

	int	y = 0;
	while (game.map[y])
	{
		int x = 0;
		while (game.map[y][x])
		{
			if (game.map[y][x] == WALL)
				mlx_put_image_to_window(game.display.mlx, game.display.win, game.wall.sprite.img, x * 64, y * 64);
			else if (game.map[y][x] == PLAYER)
				(mlx_put_image_to_window(game.display.mlx, game.display.win, game.player.sprite.img, x * 64, y * 64), \
				game.player.pos.x = x, game.player.pos.y = y);
			else if (game.map[y][x] == COIN)
				mlx_put_image_to_window(game.display.mlx, game.display.win, game.coin.sprite.img, x * 64, y * 64);
			else if (game.map[y][x] == EXIT)
				mlx_put_image_to_window(game.display.mlx, game.display.win, game.exit.sprite.img, x * 64, y * 64);
			x++;
		}
		y++;
	}

	mlx_hook(game.display.win, ON_DESTROY, 1L<<0, close_window, &game);
	mlx_key_hook(game.display.win, input, &game);
	mlx_loop_hook(game.display.mlx, update, &game);
	mlx_loop(game.display.mlx);
	
	return (0);
}