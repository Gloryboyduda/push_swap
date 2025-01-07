/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lil_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:15:57 by duandrad          #+#    #+#             */
/*   Updated: 2025/01/07 19:15:57 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while(stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
			stack = stack->next;
	}
	return(1);
}

static t_node	*find_biggest(t_node *stack)
{
	int		biggest;
	t_node	*biggest_node;

	if (!stack)
		return (NULL);
	biggest = INT_MIN;
	while (stack)
	{
		if (stack->value > biggest)
		{
			biggest = stack->value;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}

void	lil_sort(t_node **stack_a)
{
	t_node	*biggest_node;

	biggest_node = find_biggest(stack_a);
	if (*stack_a == biggest_node)
		ra(stack_a);
	else if ((*stack_a)->next == biggest_node)
		rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}