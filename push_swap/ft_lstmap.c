/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:51:24 by duarte            #+#    #+#             */
/*   Updated: 2025/01/06 15:32:30 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstmap(t_node *lst, void *(*f)(int), void (*del)(int))
{
	t_node	*map;
	t_node	*new_cont;
	int		*n;

	if (!lst || !f || !del)
		return (NULL);
	map = NULL;
	while (lst)
	{
		n = f(lst->value);
		if (!n)
			ft_lstclear(&map, del);
		new_cont = ft_lstnew(*(int *)n);
		if (!new_cont)
		{
			del(*n);
			ft_lstclear(&map, del);
			return (NULL);
		}
		ft_lstadd_back(&map, new_cont);
		lst = lst->next;
	}
	return (map);
}
