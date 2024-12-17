/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:07:47 by achu              #+#    #+#             */
/*   Updated: 2024/12/17 16:08:21 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../lib/printf/ft_printf.h"

void	move(t_manager *game, int x, int y)
{
	t_vector2	next;

	next.x = x;
	next.y = y;
	if ((*game).map[y][x] != WALL)
	{
		game->player.pos = next;
		(*game).step++;
		ft_printf("Step: %i\n", (*game).step);
	}
}
