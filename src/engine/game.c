/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:19:52 by achu              #+#    #+#             */
/*   Updated: 2025/04/18 17:08:53 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "game.h"

void	update_berry(t_game *game)
{
	uint32_t	i;

	i = 0;
	while (i < game->berry_size)
	{
		if (is_collided(game->berries[i].collider, game->player.collider) && game->berries[i].is_collected == false)
		{
			printf("test\n");
			game->berries[i].is_collected = true;
			game->score += 1000;
			game->collect += 1;
		}
		i++;
	}
}

void	update_heart(t_game *game)
{
	if (is_collided(game->heart.collider, game->player.collider) && game->collect == game->berry_size)
	{
		printf("exit\n");
	}
}

t_game	*init_game(t_display window, t_map *grid)
{
	t_game	*game;

	game = (t_game*)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->player = init_player();
	game->heart = init_heart(window, *grid);
	game->berry_size = grid->max_berry;
	game->solids = init_solid(window, *grid);
	game->solid_size = grid->max_solid;
	game->berries = init_berry(window, *grid);
	game->score = 0;
	game->timer = 0;
	game->collect = 0;
	return (game);
}
