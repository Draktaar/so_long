/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spike.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:10:22 by achu              #+#    #+#             */
/*   Updated: 2025/04/10 15:25:56 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPIKE_H
# define SPIKE_H

# include "engine.h"

typedef struct s_spike
{
	t_sprite	sprite;
	t_vec2		pos;
	t_rect		collider;
}	t_spike;

#endif