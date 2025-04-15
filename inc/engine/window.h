/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:23:23 by achu              #+#    #+#             */
/*   Updated: 2025/04/15 01:25:05 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# define GAME_WIDTH		320
# define GAME_HEIGHT	180
# define WINDOW_WIDTH	1280
# define WINDOW_HEIGHT	720
# define WINDOW_TITLE	"so_long"

# include "mlx.h"

typedef struct s_display
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
}	t_display;

t_display	init_window(void);
int32_t		destroy_window(t_display window);

#endif