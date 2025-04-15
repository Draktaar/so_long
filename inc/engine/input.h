/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:26:21 by achu              #+#    #+#             */
/*   Updated: 2025/04/14 21:25:46 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100
# define KEY_SPACE 			32
# define KEY_SHIFT 			65505
# define KEY_ESC			65307

# define ON_KEYPRESS		2
# define ON_KEYRELEASE		3
# define ON_EXPOSE			12
# define ON_DESTROY			17

# define MASK_KEYPRESS		1L<<0
# define MASK_KEYRELEASE	1L<<1
# define MASK_EXPOSE		1L<<15
# define MASK_DESTROY		1L<<17

# include <X11/X.h>
# include <X11/keysym.h>

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

typedef struct s_keybind
{
	int		key;
	int		pressed;
	int		hold;
}	t_keybind;

t_keybind	*init_input(void);
void		update_input(t_keybind *keybind);
int			input_press(int key, t_keybind *manager);
int			input_release(int key, t_keybind *manager);

#endif