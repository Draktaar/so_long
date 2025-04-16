/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spike.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:00:50 by achu              #+#    #+#             */
/*   Updated: 2025/04/15 16:58:45 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "object.h"

// static t_spike	new_spike(t_display window, float x, float y)
// {
// 	t_spike	spike;

// 	spike.sprite.img = new_xpm(window, IMG_WALL);
// 	spike.pos = (t_vec2){x * PIXEL_SIZE, y * PIXEL_SIZE};
// 	spike.collider = (t_rect){
// 		.pos = {x * PIXEL_SIZE, y * PIXEL_SIZE},
// 		.size = {PIXEL_SIZE, PIXEL_SIZE}
// 	};
// 	return (spike);
// }

// t_spike	*init_spike(t_display window, t_map grid)
// {
// 	t_spike	*berries;
// 	int32_t	i;

// 	berries = (t_spike*)malloc(grid.max_berry * sizeof(t_spike));
// 	if (!berries)
// 		return (NULL);
// 	while (i < grid.max_berry)
// 	{
// 		berries[i] = new_spike(window, grid.berry_pos[i].x, grid.berry_pos[i].y);
// 		i++;
// 	}
// 	return (berries);
// }
