/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:10:08 by achu              #+#    #+#             */
/*   Updated: 2025/01/07 16:55:49 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# define ON_KEYPRESS 2
# define ON_KEYRELEASE 3
# define ON_EXPOSE 12
# define ON_DESTROY 17

# define MASK_KEYPRESS 1L<<0
# define MASK_KEYRELEASE 1L<<1
# define MASK_EXPOSE 1L<<15
# define MASK_DESTROY 1L<<17

# ifdef __linux__
#  include "../lib/minilibx-linux/mlx.h"
#  define OS "linux"
enum e_keybind {
	KEY_W =		119,
	KEY_A =		97,
	KEY_S =		115,
	KEY_D =		100,
	KEY_SPACE =	32,
	KEY_ESC =	65307,
};
# elif __APPLE__
#  include "../lib/minilibx_opengl_20191021/mlx.h"
#  define OS "macos"
enum e_keybind {
	KEY_W =		13,
	KEY_A =		0,
	KEY_S =		1,
	KEY_D =		2,
	KEY_SPACE =	49,
	KEY_ESC =	53,
};
# endif

# include "libft.h"
# include "stdio42.h"
# include <stdio.h>

typedef struct s_vector2 {
	int x;
	int y;
}	t_vector2;

typedef struct s_rect {
	int	x_start;
	int	y_start;
	int	x_size;
	int	y_size;
}	t_rect;

typedef enum s_tile{
	EMPTY = '0',
	WALL = '1',
	COIN = 'C',
	EXIT = 'E',
	PLAYER = 'P',
}	t_tile;

typedef enum e_action {
	MOVE_UP,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT,
	JUMP,
	MAX_ACTION,
}	t_action;

typedef struct s_input {
	int		key;
	int		pressed;
	int		hold;
	double	pressed_time;
}	t_input;

typedef struct s_keybind {
	t_input MOVE_UP;
	t_input MOVE_DOWN;
	t_input MOVE_LEFT;
	t_input MOVE_RIGHT;
	t_input JUMP;
}	t_keybind;

int	input_press(int key, t_input *manager);
int	input_release(int key, t_input *manager);

#endif