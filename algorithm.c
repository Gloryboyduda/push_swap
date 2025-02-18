/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:21:50 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/18 03:27:36 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

void	three_sort(t_list **stack_a)
{
	t_list	*biggest_node;

	biggest_node = find_biggest(stack_a);
	if (*stack_a == biggest_node)
		ra(stack_a);
	else if ((*stack_a)->next == biggest_node)
		rra(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
}

void	handle_four_five(t_list **stack_a, t_list **stack_b)
{}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{}