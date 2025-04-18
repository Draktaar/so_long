/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   berry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:00:41 by achu              #+#    #+#             */
/*   Updated: 2025/04/18 17:04:31 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "object.h"

static t_berry	new_berry(t_display window, float x, float y)
{
	t_berry	strawberry;

	strawberry.is_collected = false;
	strawberry.sprite.img = new_xpm(window, IMG_BERRY);
	strawberry.pos = (t_vec2){x * PIXEL_SIZE, y * PIXEL_SIZE};
	strawberry.collider = (t_rect){
		.pos = {x * PIXEL_SIZE, y * PIXEL_SIZE},
		.size = {(PIXEL_SIZE * 2), (PIXEL_SIZE * 2)}
	};
	return (strawberry);
}

t_berry	*init_berry(t_display window, t_map grid)
{
	t_berry	*berries;
	int32_t	i;

	i = 0;
	berries = (t_berry*)malloc(grid.max_solid * sizeof(t_berry));
	if (!berries)
		return (NULL);
	while (i < grid.max_berry)
	{
		berries[i] = new_berry(window, grid.berry_pos[i].x, grid.berry_pos[i].y);
		i++;
	}
	return (berries);
}
