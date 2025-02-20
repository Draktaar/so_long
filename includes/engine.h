/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:10:08 by achu              #+#    #+#             */
/*   Updated: 2025/01/10 16:06:30 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <unistd.h>
# include <stdlib.h>
# include "../lib/printf/ft_printf.h"

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