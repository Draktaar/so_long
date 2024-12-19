/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:30:14 by achu              #+#    #+#             */
/*   Updated: 2024/12/18 21:25:54 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/so_long.h"

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
	int		len;
	char	**map;

	i = 0;
	len = parslen(file);
	map = (char **)malloc(len + 1) * sizeof(char *));
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

int	search_set(char **map, char set)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[x])
		{
			if (map[y][x] == set)
				i++;
			x++;
		}
		y++;
	}
	return (i);
}

t_display	setup_display(char **map)
{
	t_display	display;

	display.height = ft_strdlen(map);
	display.width = ft_strlen(map[0]) - 1;
	display.mlx = mlx_init();
	display.win = mlx_new_window(display.display.mlx,
			display.width, display.height, "so_long");
	return (display);
}

void	setup_game( t_manager *game)
{
	
	game->collect = search_set(game->map, 'C');
	game->step = 0;
}
