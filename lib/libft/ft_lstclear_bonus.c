/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:28:24 by achu              #+#    #+#             */
/*   Updated: 2024/11/10 17:28:24 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;

	if (!lst || !*lst || !(*del))
		return ;
	list = *lst;
	while (lst && *lst)
	{
		list = (*lst)->next;
		ft_lstdelone((*lst), (*del));
		*lst = list;
	}
}
