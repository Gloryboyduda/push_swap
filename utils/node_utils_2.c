/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:51:01 by duandrad          #+#    #+#             */
/*   Updated: 2025/01/09 16:51:01 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

t_node	*find_biggest(t_node *stack)
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

void	set_cheapest(t_node *b)
{
	long	best_match_value;
	t_node	*best_match_node;

	if (!b)
		return (NULL);
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->push_price < best_match_value)
		{
			best_match_value = b->push_price;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = 1;
}

void	set_current_position(t_node *stack)
{
	int	i;
	int	center;

	i = 0;
	if (!stack)
		return (NULL);
	center = stack_size(stack) / 2;
	while (stack)
	{
		stack->position = i;
		if (i <= center)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		i++;
	}
}

void	init_nodes(t_node *a, t_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}