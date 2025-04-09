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

t_game	*init_game(t_map *manager)
{
	t_game	*mana;

	mana = malloc(sizeof(t_game));
	if (!mana)
		exit(1);
	mana->display = setup_window(5, 13);
	mana->input = init_input();
	mana->player = init_player();

	mana->late = 0;
	mana->delta = 0;

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
	t_wall	*wall;

	curr = get_frame();
	manager->delta = curr - manager->late;
	manager->late = curr;

	mlx_clear_window(manager->display.mlx, manager->display.win);
	draw_box(manager->display, manager->player.collider, WHITE);

	//render
	for (size_t i = 0; i < 40; i++)
	{
		check_collision(&manager->player, manager->solids[i]);
	}
	update_player(&manager->player, manager->input, manager->delta);
	for (size_t i = 0; i < 40; i++)
	{
		update_collision(&manager->player, manager->solids[i]);
	}
	//render
	for (size_t i = 0; i < 40; i++)
	{
		mlx_put_image_to_window(manager->display.mlx, manager->display.win, manager->solids[i].sprite.img.ptr, manager->solids[i].collider.pos.x, manager->solids[i].collider.pos.y);
	}
	update_input(manager->input);
	mlx_do_sync(manager->display.mlx);
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
