/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:23:23 by achu              #+#    #+#             */
/*   Updated: 2025/04/11 15:51:01 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# define GAME_WIDTH		320
# define GAME_HEIGHT	180
# define WINDOW_WIDTH	1280
# define WINDOW_HEIGHT	720
# define WINDOW_TITLE	"so_long"

# include <mlx.h>
# include <X11/X.h>

typedef struct s_display
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
}	t_display;

t_display	setup_window(void);
void		destroy_window(t_display window);

#endif