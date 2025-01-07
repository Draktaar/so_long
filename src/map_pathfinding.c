/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pathfinding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:43:34 by achu              #+#    #+#             */
/*   Updated: 2025/01/07 10:37:52 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/map.h"
#include "../includes/game.h"

t_queue	*ft_qnew(int x, int y);
void	ft_append(t_queue **lst, int x, int y);
void	ft_pop(t_queue **q);
int		ft_qsize(t_queue *lst);

int	is_valid(char **map, int **visited, int x, int y)
{
	int	height;
	int	width;

	if (!(0 < x || x < width))
		return (0);
	else if (!(0 < y || y < height))
		return (0);
	else if (map[y][x] == WALL)
		return (0);
	else if (visited[y][x] == 1)
		return (0);
	visited[y][x] == 1;
	return (1);
}

int  solve(t_map *manager, t_vector2 pos)
{
	t_queue	*q;
	int		visited[100][100];

	ft_append(&q, pos.x, pos.y);
	while (ft_qsize(q) > 0)
	{
		visited[q->pos.y][q->pos.x ] = 1;
		if ((*manager).map[pos.y][pos.x] == COIN)
			manager->nb_coin++;
		if ((*manager).map[pos.y][pos.x] == EXIT)
			manager->nb_exit++;
		if (is_valid((*manager).map, visited, q->pos.x - 1, q->pos.y))
			ft_append(&q, q->pos.x - 1, q->pos.y);
		if (is_valid((*manager).map, visited, q->pos.x, q->pos.y - 1))
			ft_append(&q, q->pos.x, q->pos.y - 1);
		if (is_valid((*manager).map, visited, q->pos.x + 1, q->pos.y))
			ft_append(&q, q->pos.x + 1, q->pos.y);
		if (is_valid((*manager).map, visited, q->pos.x, q->pos.y + 1))
			ft_append(&q, q->pos.x, q->pos.y + 1);
		ft_pop(&q);
	}
	return (0);
}
