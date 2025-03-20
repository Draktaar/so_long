/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_system.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:47:42 by achu              #+#    #+#             */
/*   Updated: 2025/01/07 15:55:10 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

t_input	*init_input(void)
{
	static t_input	keybind[MAX_ACTION];
	int				i;

	i = 0;
	while (i < MAX_ACTION)
	{
		keybind[i].key = 0;
		keybind[i].hold = 0;
		keybind[i].pressed = 0;
		keybind[i].pressed_time = 0;
		i++;
	}
	keybind[MOVE_UP].key = KEY_W;
	keybind[MOVE_DOWN].key = KEY_S;
	keybind[MOVE_LEFT].key = KEY_A;
	keybind[MOVE_RIGHT].key = KEY_D;
	keybind[JUMP].key = KEY_SPACE;
	return (keybind);
}

void	update_input(t_input *keybind)
{
	double	curr_time;
	int		i;

	i = 0;
	curr_time = get_frame();
	while (i < MAX_ACTION)
	{
		if (keybind[i].pressed && (curr_time - keybind[i].pressed_time) > 0.1)
		{
			keybind[i].pressed = 0;
			keybind[i].pressed_time = 0;
		}
		i++;
	}
}

int	input_press(int key, t_input *keybind)
{
	int	i;

	i = 0;
	while (i < MAX_ACTION)
	{
		if (keybind[i].key == key)
		{
			if (keybind[i].hold == 0)
			{
				keybind[i].pressed = 1;
				keybind[i].pressed_time = get_frame();
			}
			keybind[i].hold = 1;
		}
		i++;
	}
	return (0);
}

int	input_release(int key, t_input *keybind)
{
	int	i;

	i = 0;
	while (i < MAX_ACTION)
	{
		if (keybind[i].key == key)
		{
			keybind[i].hold = 0;
			keybind[i].pressed = 0;
			keybind[i].pressed_time = 0;
		}
		i++;
	}
	return (0);
}
