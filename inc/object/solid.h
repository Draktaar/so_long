/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:10:25 by achu              #+#    #+#             */
/*   Updated: 2025/04/10 15:13:52 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLID_H
# define SOLID_H

# include "engine.h"

typedef struct s_solid
{
	t_sprite	sprite;
	t_vec2		pos;
	t_rect		collider;
}	t_solid;

#endif