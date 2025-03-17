/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:01:40 by achu              #+#    #+#             */
/*   Updated: 2025/03/17 17:38:59 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_display	setup_display(char **map)
{
	t_display	display;

	display.height = ft_strlen_dbl(map);
	display.width = ft_strlen(map[0]) - 1;
	display.mlx = mlx_init();
	display.win = mlx_new_window(display.mlx,
			display.width, display.height, "so_long");
	return (display);
}
