/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:06:07 by duandrad          #+#    #+#             */
/*   Updated: 2025/03/04 19:39:28 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(t_list **stack, int number)
{
	t_list	*tmp;
	int		min_index;

	tmp = *stack;
	min_index = tmp->index;
	while (tmp->next)
	{
		tmp = tmp->next;
		if ((tmp->index < min_index) && tmp->index != number)
			min_index = tmp->index;
	}
	return (min_index);
}

void	three_sort(t_list **a_stack)
{
	t_list *biggest_node;

	biggest_node = find_biggest(*a_stack);
	if (*a_stack == biggest_node)
		ra(a_stack);
	else if ((*a_stack)->next == biggest_node)
		rra(a_stack);
	if ((*a_stack)->content > (*a_stack)->next->content)
		sa(a_stack);
}

void	four_or_five(t_list **a_stack, t_list **b_stack)
{
	if (ft_lstsize(*a_stack) == 5)
		pb(a_stack, b_stack);
	pb(a_stack, b_stack);
	three_sort(a_stack);
	while(*b_stack)
	{
		if ((*b_stack)->content < (*a_stack)->content)
			pa(a_stack, b_stack);
		else if ((*b_stack)->content < (*a_stack)->next->content)
			(ra(a_stack), pa(a_stack, b_stack), rra(a_stack));
		else if ((*b_stack)->content < (*a_stack)->next->next->content)
		{
			if (ft_lstsize(*a_stack) == 4)
				rra(a_stack);
			(rra(a_stack), pa(a_stack, b_stack), ra(a_stack), ra(a_stack));
			if (ft_lstsize(*a_stack) == 5)
				ra(a_stack);
		}
		else if (ft_lstsize(*a_stack) == 4
			&& (*b_stack)->content < (*a_stack)->next->next->next->content)
			(rra(a_stack), pa(a_stack, b_stack), ra(a_stack), ra(a_stack));
		else
			(pa(a_stack, b_stack), ra(a_stack));
	}
}

void	radix_sort(t_list **a_stack, t_list **b_stack)
{
	size_t	size;
	int		bit_len;
	int		i;
	
	size = find_biggest((*a_stack))->index;
	bit_len = 0;
	while (size >> bit_len)
		bit_len++;
	i = -1;
	while (++i < bit_len)
	{
		size = ft_lstsize((*a_stack));
		while (size--)
		{
			if (((*a_stack)->index >> i) & 1)
				ra(a_stack);
			else
				pb(a_stack, b_stack);
		}
		while (ft_lstsize((*b_stack)))
			pa(a_stack, b_stack);
	}
}