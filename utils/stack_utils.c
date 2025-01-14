/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:31:14 by duandrad          #+#    #+#             */
/*   Updated: 2025/01/13 14:32:34 by duandrad         ###   ########.fr       */
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

int	stack_size(t_node *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_node	*last_node(t_node *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	add_last(t_node **stack, int nbr)
{
	t_node	*node;
	t_node	*last;

	if (!stack)
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (!(*stack))
	{
		*stack = node;
		node->previous = NULL;
	}
	else
	{
		last = find_last(*stack);
		last->next = node;
		node->previous = last;
	}
}