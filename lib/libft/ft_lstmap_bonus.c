/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:50:52 by achu              #+#    #+#             */
/*   Updated: 2024/11/10 17:50:53 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*new;
	void	*temp;

	if (!lst || !(*f) || !(*del))
		return (NULL);
	list = NULL;
	while (lst)
	{
		temp = (*f)(lst->content);
		new = ft_lstnew(temp);
		if (!new)
		{
			ft_lstclear(&list, (*del));
			(*del)(temp);
			return (NULL);
		}
		ft_lstadd_back(&list, new);
		lst = lst->next;
	}
	return (list);
}
