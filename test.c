/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:12:32 by afpachec          #+#    #+#             */
/*   Updated: 2025/02/18 03:31:13 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_list **a_stack, t_list **b_stack)
{
	t_list	*a_curr;
	t_list	*curr_highest;

	a_curr = a_stack[0];
	curr_highest = NULL;
	while (a_curr)
	{
		if (!curr_highest)
			curr_highest = a_curr;
		else if (a_curr->content > curr_highest->content)
			curr_highest = a_curr;
		a_curr = a_curr->next;
	}
	while (a_stack[0] != curr_highest)
		ra(a_stack);
	pb(a_stack, b_stack);
}

void	test_sort(t_list **a_stack, t_list **b_stack)
{
	size_t	length;

	length = ft_lstsize(a_stack[0]);
	while (length--)
		sort(a_stack, b_stack);
	length = ft_lstsize(b_stack[0]);
	while (length--)
	{
		rrb(b_stack);
		pa(a_stack, b_stack);
	}
}
