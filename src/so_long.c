/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:29:48 by achu              #+#    #+#             */
/*   Updated: 2025/01/07 14:37:57 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "engine/render.h"
#include "engine/input.h"
#include "common.h"
#include "system.h"
#include "map.h"

// static double	get_frame(void)
// {
// 	struct timespec ts;

// 	clock_gettime(CLOCK_MONOTONIC, &ts);
// 	return (ts.tv_sec + (ts.tv_nsec / 1.0e9));
// }

// static void	delta(t_system *manager)
// {
// 	double	curr;

// 	curr = get_frame();
// 	manager->delta = curr - manager->last;
// 	manager->last = curr;
// }

// static int	update(t_system *manager)
// {
// 	delta(manager);
// 	for (size_t i = 0; i < 314; i++)
// 	{
// 		check_ground(&manager->player, manager->solids[i].collider);
// 	}
// 	update_player(&manager->player, manager->input, manager->delta);
// 	for (size_t i = 0; i < 314; i++)
// 	{
// 		update_collision(&manager->player, manager->solids[i].collider);
// 	}
// 	update_input(manager->input);
// 	render(manager);
// 	return (0);
// }

// static int	start(t_system *manager)
// {
// 	manager->last = get_frame();

// 	mlx_loop_hook(manager->display.mlx, update, manager);
// 	mlx_hook(manager->display.win, ON_KEYPRESS, MASK_KEYPRESS, input_press, manager->input);
// 	mlx_hook(manager->display.win, ON_KEYRELEASE, MASK_KEYRELEASE, input_release, manager->input);
// 	mlx_hook(manager->display.win, ON_DESTROY, MASK_DESTROY, destroy_window, &manager->display);
// 	mlx_loop(manager->display.mlx);
	
// 	return (0);
// }

int main(int argc, char **argv)
{
	t_system	sys;
	t_game		game;
	t_map		map;

	name_banner();
	if (!init_map(&map, argc, argv))
		return (1);
	sys.map = &map;
	sys.game = &game;
	clean_map(&map);
	return (0);
}

