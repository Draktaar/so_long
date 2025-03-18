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

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include "engine.h"

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum e_keybind {
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	//Q = ESC,
	ESC = 65307,
};

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

typedef struct s_wall {
	t_sprite	sprite;
}	t_wall;

typedef struct s_coin {
	t_sprite	sprite;
	t_vector2	pos;
	int			is_collected;
}	t_coin;

typedef struct s_exit {
	t_sprite	sprite;
	int			is_open;
}	t_exit;

typedef struct s_game {
	t_display	display;
	char		**map;

	t_player	player;
	t_wall		wall;
	t_coin		coin;
	t_exit		exit;

	int			step;
	int			score;
	int			coins;
}	t_game;

char	**parse_map(char *file);
int		input(int key, t_game *game);
void	move_player(t_game *game, t_vector2 next);
int		close_window(t_game *game);
void	init_sprite(t_game *game);

#endif
