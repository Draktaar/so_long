/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:01:40 by achu              #+#    #+#             */
/*   Updated: 2025/01/07 15:54:30 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "system.h"
#include "game.h"

t_game	init_g()
{
	t_game	game;

	game.player = init_player();
	game.score = 0;
	game.timer = 0;
	return (game);
}

t_system	init_system(void)
{
	t_system	sys;

	sys.display = setup_window();
	sys.buffer = new_img(sys.display, GAME_WIDTH, GAME_HEIGHT);
	sys.scale = new_img(sys.display, WINDOW_WIDTH, WINDOW_HEIGHT);
	sys.input = init_input();
	sys.last = 0;
	sys.delta = 0;
	return (sys);
}

bool	init_game()
{

}
