/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:29:48 by achu              #+#    #+#             */
/*   Updated: 2024/12/15 18:51:42 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/sprite.h"

void	draw_pixel(t_sprite *data, int x, int y, int color)
{
	char	*pxl;

	pxl = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)pxl = color;
}

void	gizmo_rect(t_rect rect, t_sprite *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < rect.size_h)
	{
		x = 0;
		while (x < rect.size_w)
		{
			draw_pixel(data, x + rect.x, y + rect.y, rect.color);
			x++;
		}
		y++;
	}
}

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
int	update(void *ptr)
{
	t_manager	*game;

	game = (t_manager *)ptr;
	mlx_clear_window(game->display.mlx, game->display.win);
	gizmo_rect((t_rect){0, 0, 50, 50, 0x00FF0000}, &game->player.sprite);
	mlx_put_image_to_window(game->display.mlx, game->display.win, game->player.sprite.img, game->player.pos.x, game->player.pos.y);
	return (0);
}

int main(int argc, char const *argv[])
{
	t_manager	game;
	t_display window;
    t_sprite image;
	t_player	player;
	player.pos.x = 50;
	player.pos.y = 50;
    int height = (14 - 1) * 50;
    int width = 5 * 50;

    window.mlx = mlx_init();
    window.win = mlx_new_window(window.mlx , (14 - 1) * 50, 5 * 50, "so_long");

	game.display = window;
	game.player = player;
	game.player.sprite.img = mlx_new_image(game.display.mlx, 50, 50);
	game.player.sprite.addr = mlx_get_data_addr(game.player.sprite.img, &game.player.sprite.bits_per_pixel, &game.player.sprite.line_length, &game.player.sprite.endian);
	
	gizmo_rect((t_rect){0, 0, 50, 50, 0x00FF0000}, &game.player.sprite);
	mlx_put_image_to_window(game.display.mlx, game.display.win, game.player.sprite.img, game.player.pos.x, game.player.pos.y);

	mlx_hook(game.display.win, ON_DESTROY, 1L<<0, close_window, &game);
	mlx_key_hook(window.win, input, &game);
	mlx_loop_hook(game.display.mlx, update, &game);
	mlx_loop(window.mlx);
	return 0;
}

