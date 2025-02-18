/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:56:13 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/18 03:37:53 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **stack_a)
{
	t_list	*head;
	t_list	*temp;

	temp = NULL;
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	head = *stack_a;
}

void	sa(t_list **stack_a)
{
	swap(stack_a);
	fputstr("sa\n", 1);
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	fputstr("sb\n", 1);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	fputstr("ss\n", 1);
}
