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

#include <stdlib.h>
#include "system.h"

t_system	*init_system(void)
{
	t_system	*sys;

	sys = (t_system*)malloc(sizeof(t_system));
	if (!sys)
		return (NULL);
	sys->display = init_window();
	sys->buffer = new_img(sys->display, GAME_WIDTH, GAME_HEIGHT);
	sys->scale = new_img(sys->display, WINDOW_WIDTH, WINDOW_HEIGHT);
	sys->input = init_input();
	sys->last = 0;
	sys->delta = 0;
	return (sys);
}
