/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:13:03 by duandrad          #+#    #+#             */
/*   Updated: 2025/03/07 01:16:34 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	rev_rotate(t_list **stack)
{
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	second_to_last(*stack)->next = NULL;
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
