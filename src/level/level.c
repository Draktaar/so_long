/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:00:08 by achu              #+#    #+#             */
/*   Updated: 2025/04/09 22:28:30 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static t_wall	new_solid(t_display window, float x, float y)
{
	t_wall	wall;

	wall.sprite.img = new_xpm(window, IMG_WALL);
	wall.collider = (t_rect){
		.pos = {x * PIXEL_SIZE, y * PIXEL_SIZE},
		.size = {PIXEL_SIZE, PIXEL_SIZE}
	};
	return (wall);
}

static int	expand_wall(t_wall **solids, size_t *size, t_wall new)
{
	t_wall	*new_solids;
	size_t	new_size;

	new_size = *size + 1;
	new_solids = ft_realloc(*solids, *size * sizeof(t_wall), new_size * sizeof(t_wall));
	if (!new_solids)
		return (0);
	new_solids[*size] = new;
	(*solids) = new_solids;
	(*size) = new_size;
	return (1);
}

t_wall	*init_solid(t_display window, char **map)
{
	t_wall	new;
	t_wall	*solids;
	size_t	size;
	size_t	x;
	size_t	y;

	size = 0;
	solids = (t_wall *)malloc(size * sizeof(t_wall));
	if (!solids)
		return (NULL);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
			{
				new = new_solid(window, x, y);
				expand_wall(&solids, &size, new);
			}
			x++;
		}
		y++;
	}
	return (solids);
}
