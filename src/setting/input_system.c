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

t_keybind	*init_input(void)
{
	static t_keybind	button[MAX_ACTION];
	int				i;

	i = 0;
	while (i < MAX_ACTION)
	{
		button[i].key = 0;
		button[i].hold = 0;
		button[i].pressed = 0;
		button[i].pressed_time = 0;
		i++;
	}
	button[W].key = KEY_W;
	button[S].key = KEY_S;
	button[A].key = KEY_A;
	button[D].key = KEY_D;
	button[SPACE].key = KEY_SPACE;
	button[SHIFT].key = KEY_SHIFT;
	button[ESC].key = KEY_ESC;
	return (button);
}

void	update_input(t_keybind *keybind)
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

int	input_press(int key, t_keybind *keybind)
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

int	input_release(int key, t_keybind *keybind)
{
	int	i;

	i = 0;
	while (i < MAX_ACTION)
	{
		if (keybind[i].key == key)
		{
			keybind[i].hold = 0;
		}
		i++;
	}
	return (0);
}
