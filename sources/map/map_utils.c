/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:48:01 by achu              #+#    #+#             */
/*   Updated: 2025/01/07 16:56:19 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map.h"

int	is_valid_char(char c)
{
	if (c == WALL || c == EMPTY || c == COIN || c == EXIT || c == PLAYER)
		return (1);
	return (0);
}

int	is_valid_border(t_map *manager, int x, int y)
{
	int	h;
	int	w;

	h = (*manager).height - 1;
	w = (*manager).width - 1;
	if (x == 0 || y == 0 || x == w || y == h)
		if ((*manager).map[y][x] != WALL)
			return (0);
	return (1);
}

int	is_filecmp(const char *file, const char *find)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (open(file, O_RDONLY) < 0)
		return (ft_perror("Cannot open file, doesn't exist or is empty"), 0);
	i = 0;
	len = ft_strlen(file);
	while (file[i])
	{
		j = 0;
		while (find[j] && (i + j) < len && file[i + j] == find[j])
			j++;
		if (!find[j] && file[i + j] == 0)
			return (1);
		i++;
	}
	return (ft_perror("File not compatible, must use .ber files"), 0);
}

t_map	init_mapmanager(void)
{
	t_map	manager;

	manager.height = 0;
	manager.width = 0;
	manager.map = NULL;
	manager.max_player = 0;
	manager.max_exit = 0;
	manager.max_coin = 0;
	manager.nb_exit = 0;
	manager.nb_coin = 0;
	return (manager);
}
