/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:42:55 by achu              #+#    #+#             */
/*   Updated: 2025/04/11 12:55:00 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

# include <stdbool.h>

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

bool	is_point_in_rect(t_vec2 point, t_rect rect);
bool	is_collided(t_rect a, t_rect b);
t_vec2	ft_penetration(t_rect a, t_rect b);

#endif