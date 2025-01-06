/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:56:13 by duandrad          #+#    #+#             */
/*   Updated: 2025/01/06 15:32:30 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_node **stack_a)
{
	t_node *head;
	t_node *temp;

	temp = ft_lstnew(0);
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	head = *stack_a;
	temp->value = head->value;
	head->value = head->next->value;
	head->next->value = temp->value;
}

void ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}