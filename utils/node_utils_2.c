/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:51:01 by duandrad          #+#    #+#             */
/*   Updated: 2025/01/13 14:38:27 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	set_target_node(t_node *a, t_node *b)
{
	t_node	*current_a;
	t_node	*target_node;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_price(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(a);
	len_b = stack_size(b);
	while (b)
	{
		b->push_price = b->position;
		if (!(b->above_median))
			b->push_price = len_b - (b->position);
		if (b->target_node->above_median)
			b->push_price += b->target_node->position;
		else
			b->push_price += len_a - (b->target_node->position);
		b = b->next;
	}
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



void	init_nodes(t_node *a, t_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}