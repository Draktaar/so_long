/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spike.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:00:50 by achu              #+#    #+#             */
/*   Updated: 2025/04/21 21:06:00 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "object.h"

static t_spike	new_spike(t_display window, float x, float y)
{
	t_spike	spike;

	spike.sprite.img = new_xpm(window, IMG_SPIKE);
	spike.pos = (t_vec2){x * PIXEL_SIZE, y * PIXEL_SIZE};
	spike.collider = (t_rect){
		.pos = {x * PIXEL_SIZE, y * PIXEL_SIZE + 4},
		.size = {PIXEL_SIZE, PIXEL_SIZE / 2}
	};
	return (spike);
}

t_spike	*init_spike(t_display window, t_map grid)
{
	t_spike	*spikes;
	int32_t	i;

	i = 0;
	spikes = (t_spike *)malloc(grid.max_spike * sizeof(t_spike));
	if (!spikes)
		return (NULL);
	while (i < grid.max_spike)
	{
		spikes[i] = new_spike(window, grid.spike_pos[i].x, grid.spike_pos[i].y);
		i++;
	}
	return (spikes);
}
