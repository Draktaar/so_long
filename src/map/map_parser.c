/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:30:14 by achu              #+#    #+#             */
/*   Updated: 2025/04/14 16:50:34 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "map.h"

// Calcul the length of the map's height
static int	heightlen(char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

// Initialize the map
char	**parse_map(char *file)
{
	int		i;
	int		fd;
	int		len;
	char	**map;

	i = 0;
	len = heightlen(file);
	map = (char **)malloc((len + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	while (i < len)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			return (free_arr((void **)map), NULL);
		i++;
	}
	map[i] = 0;
	close(fd);
	return (map);
}
