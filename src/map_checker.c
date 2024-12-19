/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:47:43 by achu              #+#    #+#             */
/*   Updated: 2024/12/19 02:59:22 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/so_long.h"

int is_valid_border(char **map)
{
    int x;
    int y;
    int xxlen;
    int yylen;

    y = 0;
    xxlen = ft_strlen(map[0]) - 1;
    yylen = ft_strdlen(map);
    while (y < yylen)
    {
        x = 0;
        while (x < xxlen)
        {
            if (map[0][y])
                
            x++;
        }
        y++;
    }

}