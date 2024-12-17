/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:29:48 by achu              #+#    #+#             */
/*   Updated: 2024/12/17 17:14:47 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t	ft_strtlen(char *str)
{
	int	i = 0;
	
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strdlen(char **strd)
{
	int	i = 0;
	
	while (strd[i])
		i++;
	return (i);
}
float ease_in(float t)
{
	return (t * t);
}
static float ease_out(float t)
{
	return 1 - (1 - t) * (1 - t);
}

float	lerp(float start, float end, float t)
{
	return (start + ((end - start) * t));
}

int	update(void *ptr)
{
	t_manager	*game;
	
	game = (t_manager *)ptr;
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
			else if (game->map[y][x] == COLLECTIBLE)
				mlx_put_image_to_window(game->display.mlx, game->display.win, game->coin.sprite.img, x * 64, y * 64);
			x++;
		}
		y++;
	}
	return (0);
}

int main(int argc, char const *argv[])
{
	t_manager	game;

    game.display.mlx = mlx_init();
    game.display.win = mlx_new_window(game.display.mlx , (14 - 1) * 64, 5 * 64, "so_long");
	game.step = 0;
	parse(&game);
	
	game.map = init_map("./assets/map/map.txt");
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
			else if (game.map[y][x] == COLLECTIBLE)
				mlx_put_image_to_window(game.display.mlx, game.display.win, game.coin.sprite.img, x * 64, y * 64);
			x++;
		}
		y++;
	}
	
	//float time = 0;
	//float duration = 1000;
	//while (time <= duration)
	//{
	//	game.player.pos.x = lerp(64, 128, ease_out(time/duration));
	//	mlx_put_image_to_window(game.display.mlx, game.display.win, game.player.sprite.img, game.player.pos.x, game.player.pos.y);
	//	ft_printf("%i\n", time/duration);
	//	time += 0.01;
	//}
	mlx_hook(game.display.win, ON_DESTROY, 1L<<0, close_window, &game);
	mlx_key_hook(game.display.win, input, &game);
	mlx_loop_hook(game.display.mlx, update, &game);
	mlx_loop(game.display.mlx);
	return 0;
}

