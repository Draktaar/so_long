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

# define PIXEL_SIZE 64
# define IMG_WALL "assets/wall.xpm"

# define WHITE		0xFFFFFF
# define RED		0xFF0000
# define GREEN		0xFF00
# define BLUE		0x0000FF
# define YELLOW		0xFFFF00
# define CYAN		0x00FFFF
# define MAGENTA	0xFF00FF

# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_SPACE 	32
# define KEY_SHIFT 	65505
# define KEY_ESC	65307

# define ON_KEYPRESS 2
# define ON_KEYRELEASE 3
# define ON_EXPOSE 12
# define ON_DESTROY 17

# define MASK_KEYPRESS 1L<<0
# define MASK_KEYRELEASE 1L<<1
# define MASK_EXPOSE 1L<<15
# define MASK_DESTROY 1L<<17

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
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

typedef struct s_keybind
{
	int		key;
	int		pressed;
	int		hold;
}	t_keybind;

typedef enum e_action
{
	W,
	S,
	A,
	D,
	SHIFT,
	SPACE,
	ESC,
	MAX_ACTION,
}	t_action;

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
	float	x;
	float	y;
}	t_vec2;

typedef struct s_rect
{
	t_vec2	pos;
	t_vec2	size;
}	t_rect;

double	get_frame(void);

t_keybind	*init_input(void);
void	update_input(t_keybind *keybind);
int		input_press(int key, t_keybind *manager);
int		input_release(int key, t_keybind *manager);

t_rect	ft_minkowski_diff(t_rect a, t_rect b);
bool	is_point_in_rect(t_vec2 point, t_rect rect);
bool	is_collided(t_rect a, t_rect b);
bool	is_physics_collided(t_rect diff);
t_vec2	test(t_rect diff);

#endif