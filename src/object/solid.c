/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:00:08 by achu              #+#    #+#             */
/*   Updated: 2025/04/09 22:28:30 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "object.h"

static t_solid	new_solid(t_display window, float x, float y)
{
	t_solid	wall;

	wall.sprite.img = new_xpm(window, IMG_WALL);
	wall.pos = (t_vec2){x * PIXEL_SIZE, y * PIXEL_SIZE};
	wall.collider = (t_rect){
		.pos = {x * PIXEL_SIZE, y * PIXEL_SIZE},
		.size = {PIXEL_SIZE, PIXEL_SIZE}
	};
	return (wall);
}

t_solid	*init_solid(t_display window, t_map grid)
{
	t_solid	*solids;
	int32_t	i;

	i = 0;
	solids = (t_solid *)malloc(grid.max_solid * sizeof(t_solid));
	if (!solids)
		return (NULL);
	while (i < grid.max_solid)
	{
		solids[i] = new_solid(window, grid.solid_pos[i].x, grid.solid_pos[i].y);
		i++;
	}
	return (solids);
}
