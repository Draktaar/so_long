/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:05:21 by achu              #+#    #+#             */
/*   Updated: 2025/04/21 20:03:07 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/image.h"

void	update_frame(t_animation *anim, double delta)
{
	anim->frame_timer += delta;
	if (anim->frame_timer >= anim->frame_duration)
	{
		anim->frame_timer -= anim->frame_duration;
		anim->current_frame++;
		if (anim->current_frame >= anim->frame_count)
		{
			if (anim->loop)
				anim->current_frame = 0;
			else
				anim->current_frame = anim->frame_count - 1;
		}
	}
}
