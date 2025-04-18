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
#include "game.h"
#include "map.h"

static	int32_t	destroy_this(t_system *sys)
{
	return (destroy_window(sys->window));
}

static double	get_frame(void)
{
	struct timespec	ts;

	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (ts.tv_sec + (ts.tv_nsec / 1.0e9));
}

static void	delta(t_system *sys)
{
	double	curr;

	curr = get_frame();
	sys->delta = curr - sys->last;
	sys->last = curr;
}

static int32_t	update(t_system *sys)
{
	delta(sys);
	update_berry(sys->game);
	update_heart(sys->game);
	sys->game->player.is_grounded = false;
	t_rect	bottom = sys->game->player.ground_col;
	bottom.size.y += 1;
	for (size_t i = 0; i < 314; i++) {
		if (is_collided(bottom, sys->game->solids[i].collider)) {
			sys->game->player.is_grounded = true;
			break;
		}
	}
	update_player(&sys->game->player, sys->input, sys->delta);
	update_collision(&sys->game->player, sys->game->solids, sys->delta);
	update_input(sys->input);
	render(sys);
	return (0);
}

static int32_t	start(t_system *sys, t_map *grid)
{
	sys = init_system();
	sys->game = init_game(sys->window, grid);
	sys->game->bg1 = new_xpm(sys->window, IMG_BG);
	sys->game->bg0 = new_xpm(sys->window, IMG_BG0);
	sys->last = get_frame();
	mlx_loop_hook(sys->window.mlx, update, sys);
	mlx_hook(sys->window.win, ON_KEYPRESS, MASK_KEYPRESS, input_press, sys->input);
	mlx_hook(sys->window.win, ON_KEYRELEASE, MASK_KEYRELEASE, input_release, sys->input);
	mlx_hook(sys->window.win, ON_DESTROY, MASK_DESTROY, destroy_this, sys);
	mlx_loop(sys->window.mlx);
	return (0);
}

int32_t	main(int32_t argc, char **argv)
{
	t_system	sys;
	t_map		grid;

	name_banner();
	if (!setup_map(&grid, argc, argv))
		return (1);
	start(&sys, &grid);
	clean_map(&grid);
	return (0);
}

