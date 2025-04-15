/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 01:31:31 by achu              #+#    #+#             */
/*   Updated: 2025/04/14 01:48:21 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMER_H
# define TIMER_H

# include <stdint.h>
# include <stdbool.h>

typedef struct s_timer
{
	float	duration;
	float	time_left;
	bool	is_active;
}	t_timer;

t_timer	init_timer(void);
void	timer_start(t_timer *timer, float duration);
void	timer_update(t_timer *timer, double delta);
void	timer_stop(t_timer *timer);

#endif