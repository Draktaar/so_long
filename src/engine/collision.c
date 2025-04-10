/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:41:16 by achu              #+#    #+#             */
/*   Updated: 2025/04/10 15:24:32 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "math.h"

// Return True if a vector is inside a rect
bool	is_point_in_rect(t_vec2 point, t_rect rect)
{
	return (point.x >= rect.pos.x
		&& point.x <= rect.pos.x + rect.size.x
		&& point.y >= rect.pos.y
		&& point.y <= rect.pos.y + rect.size.y);
}

// Return True if a rect is inside a rect
bool	is_collided(t_rect a, t_rect b)
{
	return (a.pos.x < b.pos.x + b.size.x
		&& a.pos.x + a.size.x > b.pos.x
		&& a.pos.y < b.pos.y + b.size.y
		&& a.pos.y + a.size.y > b.pos.y);
}

// Return the value of penetration from the overlap of two rect
t_vec2	ft_penetration(t_rect a, t_rect b)
{
	t_vec2	overlap;

	overlap.x = fmin(fabs(a.pos.x + a.size.x - b.pos.x), fabs(b.pos.x + b.size.x - a.pos.x));
	overlap.y = fmin(fabs(a.pos.y + a.size.y - b.pos.y), fabs(b.pos.y + b.size.y - a.pos.y));
	return (overlap);
}
