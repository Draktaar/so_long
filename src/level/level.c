/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:00:08 by achu              #+#    #+#             */
/*   Updated: 2025/03/27 01:12:43 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static t_wall	new_solid(t_display window, float x, float y)
{
	t_wall	wall;

	wall.sprite.img = new_img(IMG_WALL, window);
	wall.collider = (t_rect){
		.pos = {x * PIXEL_SIZE, y * PIXEL_SIZE},
		.size = {PIXEL_SIZE, PIXEL_SIZE}
	};
	return (wall);
}

static t_wall	*parse_line(t_display window, int y, char *map)
{
	t_wall *line;
	int 	x;

	line = (t_wall *)malloc(window.width * sizeof(t_wall));
	if (!line)
		return (NULL);
	x = 0;
	while (map[x])
	{
		if (map[x] == '1')
			line[x] = new_solid(window, x, y);
		else
			line[x] = (t_wall){0};
		x++;
	}
	return (line);
}

t_wall	**init_solid(t_display window, char **map)
{
	t_wall	**solids;
	int		y;

	solids = (t_wall **)malloc(window.height * sizeof(t_wall *));
	if (!solids)
		return (NULL);
	y = 0;
	while (map[y])
	{
		solids[y] = parse_line(window, y, map[y]);
		if (!solids[y])
			return (NULL);
		y++;
	}
	return (solids);
}
