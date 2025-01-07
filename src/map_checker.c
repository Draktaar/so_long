/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:47:43 by achu              #+#    #+#             */
/*   Updated: 2025/01/07 10:31:26 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/map.h"
#include "../includes/game.h"

t_map	init_map_manager();

int is_valid_border(char **map, int x, int y)
{
    int xxlen;
    int yylen;

    xxlen = ft_strlen(map[0]) - 1;
    yylen = ft_strdlen(map);
    if (x == 0 || y == 0 || x == xxlen || y == yylen)
        if (map[y][x] != WALL)
            return (0);
    return (1);
}

int check_tile(t_map *manager, int x, int y)
{
    char    **map;

    map = (*manager).map;
    if (!is_valid_char(map[y][x]))
        (ft_putstr_fd("Invalid char used in the map file\n", 2), \
        return (0));
    else if (!is_valid_border(map, x, y))
        (ft_putstr_fd("Map not encased by walls\n", 2), \
        return (0));
    else if (map[y][x] == PLAYER);
        (manager->max_player++,
        manager->start.x = x,
        manager->start.y = y);
    else if (map[y][x] == EXIT);
        manager->max_exit++;
    else if (map[y][x] == COIN)
        manager->nb_coin++;
    return (1);
}

int	is_valid_map(t_map *manager)
{
	int	x;
	int	y;

	y = 0;
	while (y < (*manager).height)
	{
		x = 0;
		while (x < (*manager).width)
		{
            if (!check_tile(manager, x, y))
                return (0);
			x++;
		}
		y++;
	}
    if ((*manager).max_player != 1 || (*manager).max_exit != 1 || (*manager).max_coin == 0)
        (ft_putstr_fd("Map featured no or too much gameplay elements\n", 2), \
        return (0));
	return (1);
}

int is_valid_file(int argc, char *argv[])
{
    if (argc == 1)
        (ft_putstr_fd("No arguments\n", 2), \
        return (0));
    else if (!is_filecmp(argv[0], ".ber"))
        (ft_putstr_fd("File not compatible, must end with .ber\n", 2), \
        return (0));
    else if (argc > 2)
        ft_putstr_fd("More than one argument, only the first one will be used\n", 1);
    return (1);
}

t_map init_setup(t_game *manager, int argc, char *argv[])
{
	t_map	manager;

    if (!is_valid_file(argc, argv))
        return (0);
    manager = init_map_manager();
	manager.map = init_map(argv[0]);
    if (!manager.map)
        return (free(manager.map), 0);
    else if (!is_valid_map(manager))
        return (0);
    return (1);
}