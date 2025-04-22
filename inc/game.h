/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:11:06 by achu              #+#    #+#             */
/*   Updated: 2025/01/07 16:59:22 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <stdint.h>
# include "engine/window.h"
# include "object/player.h"
# include "object/object.h"

typedef struct s_game
{
	t_img		bg0;
	t_img		bg1;

	t_player	player;
	t_heart		heart;
	t_berry		*berries;
	uint32_t	berry_count;
	t_solid		*solids;
	uint32_t	solid_count;
	t_spike		*spikes;
	uint32_t	spike_count;

	bool		is_gameover;
	uint32_t	collect;
	double		timer_start;
	double		timer_elapsed;
}	t_game;

t_game	*init_game(t_display window, t_map *grid);
void	update_berry(t_game *game);
void	update_heart(t_game *game);
void	update_spike(t_game *game);
void	destroy_game(t_game *game);

#endif
