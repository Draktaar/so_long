/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:19:52 by achu              #+#    #+#             */
/*   Updated: 2025/04/22 03:08:48 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "game.h"

void	update_berry(t_game *game)
{
	uint32_t	i;

	i = 0;
	while (i < game->berry_count)
	{
		if (is_collided(game->berries[i].collider, game->player.collider) && game->berries[i].is_collected == false)
		{
			game->berries[i].is_collected = true;
			game->collect += 1;
			if (game->collect == game->berry_count)
				game->heart.is_opened = true;
		}
		i++;
	}
}

void	update_heart(t_game *game)
{
	if (is_collided(game->heart.collider, game->player.collider) && game->collect == game->berry_count)
		game->is_gameover = true;
}

void	update_spike(t_game *game)
{
	uint32_t	i;

	i = 0;
	while (i < game->spike_count)
	{
		if (is_collided(game->spikes[i].collider, game->player.collider))
			game->is_gameover = true;
		i++;
	}
}

void	destroy_game(t_game *game)
{
	uint32_t	i;

	i = 0;
	while (i < game->berry_count)
	{
		destroy_img(game->berries[i].sprite.img);
		i++;
	}
	i = 0;
	while (i < game->solid_count)
	{
		destroy_img(game->solids[i].sprite.img);
		i++;	
	}
	i = 0;
	while (i < game->spike_count)
	{
		destroy_img(game->spikes[i].sprite.img);
		i++;
	}
	destroy_img(game->heart.sprite.img);
	destroy_img(game->bg0);
	destroy_img(game->bg1);
	free(game->berries);
	free(game->solids);
	free(game->spikes);
}
	

t_game	*init_game(t_display window, t_map *grid)
{
	t_game	*game;

	game = (t_game*)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->player = init_player(*grid);
	game->heart = init_heart(window, *grid);
	game->berries = init_berry(window, *grid);
	game->solids = init_solid(window, *grid);
	game->spikes = init_spike(window, *grid);
	game->solid_count = grid->max_solid;
	game->berry_count = grid->max_berry;
	game->spike_count = grid->max_spike;
	game->is_gameover = false;
	game->collect = 0;
	game->timer_start = 0.0f;
	game->timer_elapsed = 0.0f;
	return (game);
}
