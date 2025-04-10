/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:01:40 by achu              #+#    #+#             */
/*   Updated: 2025/01/07 15:54:30 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "game.h"

t_system	*init_game(t_map *manager)
{
	t_system	*sys;

	sys = malloc(sizeof(t_system));
	if (!sys)
		exit(1);
	sys->display = setup_window();
	sys->game = new_img(sys->display, GAME_WIDTH, GAME_HEIGHT);
	sys->screen = new_img(sys->display, WINDOW_WIDTH, WINDOW_HEIGHT);
	sys->input = init_input();
	sys->last = 0;
	sys->delta = 0;
	sys->player = init_player();
	return (sys);
}

double	get_frame(void)
{
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (ts.tv_sec + (ts.tv_nsec / 1.0e9));
}

static int	update(t_system *manager)
{
	double	curr;

	curr = get_frame();
	manager->delta = curr - manager->last;
	manager->last = curr;

	//render
	for (size_t i = 0; i < 63; i++)
	{
		check_ground(&manager->player, manager->solids[i].collider);
	}
	update_player(&manager->player, manager->input, manager->delta);
	for (size_t i = 0; i < 63; i++)
	{
		update_collision(&manager->player, manager->solids[i].collider);
	}
	update_input(manager->input);
	render(manager);
	return (0);
}

int	start(t_system *manager)
{
	manager->last = get_frame();

	mlx_loop_hook(manager->display.mlx, update, manager);
	mlx_hook(manager->display.win, ON_KEYPRESS, MASK_KEYPRESS, input_press, manager->input);
	mlx_hook(manager->display.win, ON_KEYRELEASE, MASK_KEYRELEASE, input_release, manager->input);
	//mlx_hook(manager->display.win, ON_DESTROY, MASK_DESTROY, close_window, manager);
	mlx_loop(manager->display.mlx);
	
	return (0);
}
