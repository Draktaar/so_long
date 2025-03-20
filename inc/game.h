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

# define WINDOW_TITLE "so_long"

# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include "engine.h"

typedef struct s_display {
	void	*mlx;
	void	*win;
	int		height;
	int		width;
}	t_display;

typedef struct s_sprite {
	void	*img;
	char	*addr;
	int		h;
	int		w;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_sprite;

//*** Gameobjects ***
typedef struct s_player {
	t_sprite	sprite;
	t_vector2	pos;
}	t_player;

typedef struct s_game {
	t_display	display;
	t_input		*input;
	char		**map;

	t_player	player;

	int			step;
	int			score;
	int			coins;
}	t_game;

int		start(t_game *manager);
double get_time();
t_input	*init_input();
void	update_input(t_input *keybind);

#endif
