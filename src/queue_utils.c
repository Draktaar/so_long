/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:29:56 by achu              #+#    #+#             */
/*   Updated: 2025/01/07 10:01:23 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/map.h"
#include "../includes/engine.h"

t_queue    *ft_qnew(int x, int y)
{
    t_vector2    pos;
    t_queue        *q;

    q = (t_queue *)malloc(sizeof(t_queue));
    if (!q)
        return (NULL);
    pos.x = x;
    pos.y = y;
    q->pos = pos;
    q->next = 0;
    return (q);
}

void    ft_append(t_queue **q, int x, int y)
{
    t_queue *new;

    new = ft_qnew(x, y);
    new->next = *q;
    *q = new;
}

void    ft_pop(t_queue **q)
{
    t_queue *list;
    t_queue *temp;

    if (!q || !*q)
        return ;
    temp = *q;
    list = temp;
    *q = temp->next;
    free(list);
}

int    ft_qsize(t_queue *q)
{
    int        i;
    t_queue    *temp;

    i = 1;
    temp = q;
    while (temp->next != q)
    {
        temp = temp->next;
        i++;
    }
    return (i);
}