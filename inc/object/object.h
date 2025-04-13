/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:15:59 by achu              #+#    #+#             */
/*   Updated: 2025/04/11 00:10:17 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <stdbool.h>
# include "engine/image.h"
# include "engine/vec.h"

typedef struct s_berry
{
	t_sprite	sprite;
	t_vec2		pos;
	t_rect		collider;
	bool		collected;
}	t_berry;

typedef struct s_solid
{
	t_sprite	sprite;
	t_vec2		pos;
	t_rect		collider;
}	t_solid;

typedef struct s_spike
{
	t_sprite	sprite;
	t_vec2		pos;
	t_rect		collider;
}	t_spike;

t_solid	*init_solid(t_display window, char **map);

#endif