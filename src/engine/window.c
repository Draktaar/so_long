/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:30:50 by achu              #+#    #+#             */
/*   Updated: 2025/04/09 22:31:25 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// Setup window of the game, and store it inside display
t_display	setup_window(void)
{
	t_display	display;
	void		*mlx_ptr;
	void		*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(
			mlx_ptr,
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			WINDOW_TITLE);
	display.mlx = mlx_ptr;
	display.win = win_ptr;
	display.width = WINDOW_WIDTH;
	display.height = WINDOW_HEIGHT;
	return (display);
}

void	destroy_window()
{
	
}
