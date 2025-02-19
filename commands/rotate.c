/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:19:38 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/19 17:19:30 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = NULL;
}

void	ra(t_list **a)
{
	rotate(a);
	ft_fputstr("ra\n", 1);
}

void	rb(t_list **b)
{
	rotate(b);
	ft_fputstr("rb\n", 1);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	ft_fputstr("rr\n", 1);
}
