/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:31:14 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/19 17:45:30 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	stack_sorted(t_list *stack)
{
	if (!stack)
		return (false);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	ft_lstadd_back(t_list **lst, t_list *new_)
{
	t_list	*ptr;

	if (!*lst)
	{
		*lst = new_;
		return ;
	}
	ptr = ft_lstlast(*lst);
	ptr->next = new_;
	new_->next = NULL;
}

void	ft_lstadd_front(t_list **lst, t_list *new_)
{
	new_->next = *lst;
	*lst = new_;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*deleter;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		deleter = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = deleter;
	}
	*lst = 0;
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(NULL);
	free(lst);
}
