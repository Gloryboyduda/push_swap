/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:50:21 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/12 18:07:29 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*find_biggest(t_list *stack)
{
	int		biggest;
	t_list	*biggest_list;

	if (!stack)
		return (NULL);
	biggest = INT_MIN;
	while (stack)
	{
		if (stack->content > biggest)
		{
			biggest = stack->content;
			biggest_list = stack;
		}
		stack = stack->next;
	}
	return (biggest_list);
}

t_list	*find_smallest(t_list *stack)
{
	long	smallest;
	t_list	*smallest_list;

	if (!stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->content < smallest)
		{
			smallest = stack->content;
			smallest_list = stack;
		}
		stack = stack->next;
	}
	return (smallest_list);
}
