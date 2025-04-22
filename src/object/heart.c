/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heart.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 03:39:42 by achu              #+#    #+#             */
/*   Updated: 2025/04/22 00:58:46 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/image.h"
#include "common.h"
#include "object.h"

static t_animation	init_anim(void)
{
	t_animation	anim;

	anim.col = 23;
	anim.row = 1;
	anim.width = 20;
	anim.height = 20;
	anim.current_frame = 0;
	anim.frame_count = 23;
	anim.frame_duration = 0.1f;
	anim.frame_timer = 0.0f;
	anim.loop = true;
	return (anim);
}

t_heart	init_heart(t_display window, t_map grid)
{
	t_heart	heart;

	heart.is_opened = false;
	heart.sprite.anim = init_anim();
	heart.sprite.img = new_xpm(window, IMG_HEART);
	heart.pos = (t_vec2){grid.heart_pos.x * PIXEL_SIZE, grid.heart_pos.y * PIXEL_SIZE};
	heart.collider = (t_rect){
		.pos = {grid.heart_pos.x * PIXEL_SIZE, grid.heart_pos.y * PIXEL_SIZE},
		.size = {PIXEL_SIZE * 2, PIXEL_SIZE * 2}
	};
	return (heart);
}
