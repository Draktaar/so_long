/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:05:24 by achu              #+#    #+#             */
/*   Updated: 2025/04/12 19:47:35 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "engine/image.h"
# include "engine/vec.h"
# include "system.h"

# define WHITE		    0xFFFFFF
# define RED		    0xFF0000
# define GREEN		    0xFF00
# define BLUE		    0x0000FF
# define YELLOW		    0xFFFF00
# define CYAN		    0x00FFFF
# define MAGENTA	    0xFF00FF

void	render(t_system *game);
void	draw_bg(t_img *game);
void	draw_square(t_img *image, t_rect rect, int color);
void	draw_rect(t_img *image, t_rect rect, int color);
void    name_banner(void);

#endif