/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:10:08 by achu              #+#    #+#             */
/*   Updated: 2025/01/07 16:55:49 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "libft.h"
# include "stdio42.h"

typedef struct s_vector2 {
	int x;
	int y;
}	t_vector2;

typedef enum s_type{
	EMPTY = '0',
	WALL = '1',
	COIN = 'C',
	EXIT = 'E',
	PLAYER = 'P',
}	t_type;

#endif