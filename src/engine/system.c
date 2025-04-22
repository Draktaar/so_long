/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:01:40 by achu              #+#    #+#             */
/*   Updated: 2025/01/07 15:54:30 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include "system.h"

double	get_frame(void)
{
	struct timespec	ts;

	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (ts.tv_sec + (ts.tv_nsec / 1.0e9));
}

t_system	*init_system(void)
{
	t_system	*sys;

	sys = (t_system*)malloc(sizeof(t_system));
	if (!sys)
		return (NULL);
	sys->window = init_window();
	sys->buffer = new_img(sys->window, GAME_WIDTH, GAME_HEIGHT);
	sys->scale = new_img(sys->window, WINDOW_WIDTH, WINDOW_HEIGHT);
	sys->input = init_input();
	sys->last = 0;
	sys->delta = 0;
	return (sys);
}

int32_t	destroy_system(t_system	*sys)
{
	destroy_game(sys->game);
	clean_map(sys->grid);
	destroy_img(sys->buffer);
	destroy_img(sys->scale);
	free(sys->game);
	destroy_window(sys->window);
	free(sys);
	exit(0);
}
