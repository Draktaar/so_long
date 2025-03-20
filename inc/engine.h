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

# define WINDOW_TITLE "so_long"

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00

# define ON_KEYPRESS 2
# define ON_KEYRELEASE 3
# define ON_EXPOSE 12
# define ON_DESTROY 17

# define MASK_KEYPRESS 1L<<0
# define MASK_KEYRELEASE 1L<<1
# define MASK_EXPOSE 1L<<15
# define MASK_DESTROY 1L<<17

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <time.h>
# include "libft.h"
# include "stdio42.h"
# include <stdio.h>

typedef struct s_display
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
}	t_display;

enum e_keybind
{
	KEY_W =		119,
	KEY_A =		97,
	KEY_S =		115,
	KEY_D =		100,
	KEY_SPACE =	32,
	KEY_ESC =	65307,
};

typedef enum e_action
{
	MOVE_UP,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT,
	JUMP,
	MAX_ACTION,
}	t_action;

typedef struct s_input
{
	int		key;
	int		pressed;
	int		hold;
	double	pressed_time;
}	t_input;

typedef enum s_tile
{
	EMPTY = '0',
	WALL = '1',
	COIN = 'C',
	EXIT = 'E',
	PLAYER = 'P',
}	t_tile;

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_rect
{
	t_vec2	pos;
	t_vec2	size;
}	t_rect;

double	get_frame(void);

t_input	*init_input(void);
void	update_input(t_input *keybind);
int		input_press(int key, t_input *manager);
int		input_release(int key, t_input *manager);

bool	is_point_in_rect(t_vec2 point, t_rect rect);
bool	is_collided(t_rect a, t_rect b);

#endif