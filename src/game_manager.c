/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:01:40 by achu              #+#    #+#             */
/*   Updated: 2024/12/20 17:04:32 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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