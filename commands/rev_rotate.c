/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:13:03 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/19 17:56:52 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	rev_rotate(t_list **stack)
{
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	ft_lstpenultimate(*stack)->next = NULL; 
	last->next = *stack;
	*stack = last;
}

void	rra(t_list **a)
{
	rev_rotate(a);
	ft_fputstr("rra\n", 1);
}

void	rrb(t_list **b)
{
	rev_rotate(b);
	ft_fputstr("rrb\n", 1);
}

void	rrr(t_list **a, t_list **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_fputstr("rrr\n", 1);
}
