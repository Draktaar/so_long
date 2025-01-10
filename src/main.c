/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:29:48 by achu              #+#    #+#             */
/*   Updated: 2025/01/10 15:40:21 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// {
// 	return (t * t);
// }
// static float ease_out(float t)
// {
// 	return 1 - (1 - t) * (1 - t);
// }

// float	lerp(float start, float end, float t)
// {
// 	return (start + ((end - start) * t));
// }

	//float time = 0;
	//float duration = 1000;
	//while (time <= duration)
	//{
	//	game.player.pos.x = lerp(64, 128, ease_out(time/duration));
	//	mlx_put_image_to_window(game.display.mlx, game.display.win, game.player.sprite.img, game.player.pos.x, game.player.pos.y);
	//	ft_printf("%i\n", time/duration);
	//	time += 0.01;
	//}


#include "libft.h"
#include "../includes/map.h"
#include "../includes/game.h"

int	update(void *ptr);

// float ease_in(float t)
// {
// 	return (t * t);
// }
// static float ease_out(float t)
// {
// 	return 1 - (1 - t) * (1 - t);
// }

// float	lerp(float start, float end, float t)
// {
// 	return (start + ((end - start) * t));
// }


int	main(int argc, char const *argv[])
{
	t_map	manager;

	if (!init_setup(&manager, argc, argv))
		return (0);
	start(&manager);
	return (1);
}
