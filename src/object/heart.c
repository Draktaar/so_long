/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heart.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 03:39:42 by achu              #+#    #+#             */
/*   Updated: 2025/04/18 16:51:01 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "object.h"

t_heart	init_heart(t_display window, t_map grid)
{
	t_heart	heart;

	heart.is_opened = false;
	heart.sprite.img = new_xpm(window, IMG_HEART);
	heart.pos = (t_vec2){grid.heart_pos.x * PIXEL_SIZE, grid.heart_pos.y * PIXEL_SIZE};
	heart.collider = (t_rect){
		.pos = {grid.heart_pos.x * PIXEL_SIZE, grid.heart_pos.y * PIXEL_SIZE},
		.size = {PIXEL_SIZE * 2, PIXEL_SIZE * 2}
	};
	return (heart);
}
