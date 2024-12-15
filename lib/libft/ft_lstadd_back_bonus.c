/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:15:06 by achu              #+#    #+#             */
/*   Updated: 2024/11/10 17:15:09 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*list;

	if (!lst || !new)
		return ;
	list = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (list->next)
		list = list->next;
	list->next = new;
}
