/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:15:59 by achu              #+#    #+#             */
/*   Updated: 2025/04/21 20:55:23 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <stdbool.h>
# include "engine/image.h"
# include "engine/vec.h"
# include "map.h"

typedef struct s_heart
{
	t_vec2		pos;
	t_sprite	sprite;
	t_rect		collider;
	bool		is_opened;
}	t_heart;

typedef struct s_berry
{
	t_vec2		pos;
	t_sprite	sprite;
	t_rect		collider;
	bool		is_collected;
}	t_berry;

typedef struct s_solid
{
	t_vec2		pos;
	t_sprite	sprite;
	t_rect		collider;
}	t_solid;

typedef struct s_spike
{
	t_vec2		pos;
	t_sprite	sprite;
	t_rect		collider;
}	t_spike;

t_heart	init_heart(t_display window, t_map grid);
t_berry	*init_berry(t_display window, t_map grid);
t_solid	*init_solid(t_display window, t_map grid);
t_spike	*init_spike(t_display window, t_map grid);

#endif