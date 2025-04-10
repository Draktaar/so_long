/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   berry.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:10:27 by achu              #+#    #+#             */
/*   Updated: 2025/04/10 15:14:05 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BERRY_H
# define BERRY_H

# include "engine.h"

typedef struct s_berry
{
	t_sprite	sprite;
	t_vec2		pos;
	t_rect		collider;
}	t_berry;

#endif