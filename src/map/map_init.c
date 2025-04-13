/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:14:10 by achu              #+#    #+#             */
/*   Updated: 2025/04/13 19:13:24 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "map.h"

static t_map	init_map(void)
{
	t_map	manager;

	manager.height = 0;
	manager.width = 0;
	manager.map = NULL;
	manager.visited = NULL;
	manager.max_player = 0;
	manager.max_exit = 0;
	manager.max_coin = 0;
	manager.nb_exit = 0;
	manager.nb_coin = 0;
	return (manager);
}

void	clean_map(t_map *manager)
{
	free_arr((void **)manager->map);
	free_arr((void **)manager->visited);
	manager->height = 0;
	manager->width = 0;
	manager->max_player = 0;
	manager->max_exit = 0;
	manager->max_coin = 0;
	manager->nb_exit = 0;
	manager->nb_coin = 0;
}

int	setup_map(t_map *manager, int argc, char **argv)
{
	if (!is_valid_file(argc, argv))
		return (0);
	*manager = init_map();
	manager->map = parse_map(argv[1]);
	if (!manager->map)
		return (ft_perror("Map not initialize"), 0);
	manager->width = ft_strlen(manager->map[0]) - 1;
	manager->height = ft_arrlen(manager->map);
	if (!is_valid_map(manager))
		return (clean_map(manager), 0);
	else if (!is_valid_pathfinder(manager))
		return (clean_map(manager), 0);
	return (1);
}
