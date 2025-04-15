/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 01:36:57 by achu              #+#    #+#             */
/*   Updated: 2025/04/14 01:48:14 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/timer.h"

t_timer	init_timer(void)
{
	t_timer	timer;

	timer.duration = 0;
	timer.time_left = 0;
	timer.is_active = false;
	return (timer);
}

void	timer_start(t_timer *timer, float duration)
{
	timer->duration = duration;
	timer->time_left = duration;
	timer->is_active = true;
}

void	timer_update(t_timer *timer, double delta)
{
	if (timer->is_active)
	{
		timer->time_left -= delta;
		if (timer->time_left <= 0)
			timer_stop(timer);
	}
}

void	timer_stop(t_timer *timer)
{
	timer->time_left = 0;
	timer->is_active = false;
}