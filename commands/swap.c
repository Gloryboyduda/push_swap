/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:56:13 by duandrad          #+#    #+#             */
/*   Updated: 2025/03/07 11:55:50 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **stack_a)
{
	t_list	*temp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = temp->next;
	temp->next = (*stack_a);
	*stack_a = temp;
}

void	sa(t_list **stack_a)
{
	swap(stack_a);
	ft_fputstr("sa\n", 1);
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	ft_fputstr("sb\n", 1);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_fputstr("ss\n", 1);
}
