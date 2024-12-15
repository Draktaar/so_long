/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:30:14 by achu              #+#    #+#             */
/*   Updated: 2024/12/15 15:40:17 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	clear(char **strd)
{
	int	i;

	i = 0;
	while (strd[i])
	{
		free(strd[i]);
		i++;
	}
	free(strd);
}

int	parslen(char *file)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd))
		i++;
	return (i);
}

char	**init_map(char *file)
{
	int		i;
	int		fd;
	char	**map;

	i = 0;
	fd = open(file, O_RDONLY);
	map = (char **)malloc((parslen(file) + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	while (i < parslen(file))
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			return (clear(map), NULL);
		i++;
	}
	map[i] = 0;
	return (map);
}
