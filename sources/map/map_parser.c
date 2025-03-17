/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:30:14 by achu              #+#    #+#             */
/*   Updated: 2025/03/17 17:04:09 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game.h"

static void	clear_map(char **strd)
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

static int	parslen(char *file)
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
	int		len;
	char	**map;

	i = 0;
	len = parslen(file);
	map = (char **)malloc((len + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	while (i < len)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			return (clear_map(map), NULL);
		i++;
	}
	map[i] = 0;
	return (map);
}
