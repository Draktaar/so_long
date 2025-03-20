/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:01:40 by achu              #+#    #+#             */
/*   Updated: 2025/01/07 15:54:30 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "game.h"

// Setup window of the game, and store it inside display
t_display	setup_display(int height, int width)
{
	t_display	display;
	void		*mlx_ptr;
	void		*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(
			mlx_ptr,
			width * 64,
			height * 64,
			WINDOW_TITLE);
	display.mlx = mlx_ptr;
	display.win = win_ptr;
	display.height = height;
	display.width = width;
	return (display);
}

t_game	*init_game(t_map *manager)
{
	t_game	*mana;

	mana = malloc(sizeof(t_game));
	if (!mana)
		exit(1);
	mana->display = setup_display(manager->height, manager->width);
	mana->input = init_input();

	mana->late = 0;
	mana->delta = 0;

	mana->player.collider = (t_rect){
		.pos = {150, 150},
		.size = {100, 100}
	};
	mana->map = (*manager).map;

	mana->step = 0;
	mana->score = 0;
	mana->coins = (*manager).max_coin;
	return (mana);
}

double get_frame()
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (ts.tv_sec + (ts.tv_nsec / 1.0e9));
}

static int	update(t_game *manager)
{
	double	curr;

	curr = get_frame();
	manager->delta = curr - manager->late;
	manager->late = curr;
	mlx_clear_window(manager->display.mlx, manager->display.win);
	update_input(manager->input);
	player_movement(&manager->player.collider, manager->input, manager->delta);
	draw_rect(&manager->display, manager->player.collider);
	mlx_do_sync(manager->display.mlx);
	usleep(10000);
	return (0);
}

int	start(t_game *manager)
{
	manager->late = get_frame();
	mlx_loop_hook(manager->display.mlx, update, manager);
	mlx_hook(manager->display.win, ON_KEYPRESS, MASK_KEYPRESS, input_press, manager->input);
	mlx_hook(manager->display.win, ON_KEYRELEASE, MASK_KEYRELEASE, input_release, manager->input);
	//mlx_hook(manager->display.win, ON_DESTROY, MASK_DESTROY, close_window, manager);
	mlx_loop(manager->display.mlx);
	
	return (0);
}
