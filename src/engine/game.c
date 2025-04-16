/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:19:52 by achu              #+#    #+#             */
/*   Updated: 2025/04/15 19:09:29 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game.h"

t_game	*init_game(void)
{
	t_game	*game;

	game = (t_game*)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->player = init_player();
	game->score = 0;
	game->timer = 0;
	return (game);
}
