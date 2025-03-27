/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:29:48 by achu              #+#    #+#             */
/*   Updated: 2025/01/07 14:37:57 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "game.h"

t_game	*init_game(t_map *manager);

int main(int argc, char **argv)
{
	t_game	*g_manager;
	t_map	m_manager;

	if (!init_map(&m_manager, argc, argv))
		return (1);
	g_manager = init_game(&m_manager);
	//g_manager->solids = init_solid( g_manager->display, m_manager.map);
	start(g_manager);
	clean_map(&m_manager);
	return (0);
}

