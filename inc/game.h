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

# define ACCELERATION 200

# include "engine.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		h;
	int		w;
}	t_img;

typedef struct s_player
{
	t_img		sprite;
	t_vec2		velocity;
	t_rect		collider;
}	t_player;

typedef struct s_game
{
	t_display	display;
	t_input		*input;

	double		late;
	double		delta;

	char		**map;

	t_player	player;

	int			step;
	int			score;
	int			coins;
}	t_game;

int		start(t_game *manager);
int		draw_rect(t_display *data, t_rect rect);
void	player_movement(t_rect *player, t_input *keybind, double delta);

#endif
