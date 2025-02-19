/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:21:50 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/19 18:47:57 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap.h"

void	real_four_five_sort(t_list **a_stack, t_list **b_stack)
{
	if (ft_lstsize(a_stack[0]) == 5)
		pb(a_stack, b_stack);
	(pb(a_stack, b_stack), three_sort(a_stack));
	while (b_stack[0])
	{
		if (b_stack[0]->content < a_stack[0]->content)
			pa(a_stack, b_stack);
		else if (b_stack[0]->content < a_stack[0]->next->content)
			(ra(a_stack), pa(a_stack, b_stack), rra(a_stack));
		else if (b_stack[0]->content < a_stack[0]->next->next->content)
		{
			if (ft_lstsize(a_stack[0]) == 4)
				rra(a_stack);
			(rra(a_stack), pa(a_stack, b_stack), ra(a_stack), ra(a_stack));
			if (ft_lstsize(a_stack[0]) == 5)
				ra(a_stack);
		}
		else if (ft_lstsize(a_stack[0]) == 4
			&& b_stack[0]->content < a_stack[0]->next->next->next->content)
			(rra(a_stack), pa(a_stack, b_stack), ra(a_stack), ra(a_stack));
		else
			(pa(a_stack, b_stack), ra(a_stack));
	}
}

void	specific_cases(t_list **a, t_list **b)
{
	int	fourth;
	int	fifth;

	fourth = a[0]->next->next->next->content;
	fifth = a[0]->next->next->next->next->content;
	if (a[0]->index != 2
		|| (a[0]->next->index != 3 && a[0]->next->index != 1))
		return ;
	if (a[0]->next->next->content == 2 && fourth == 1 && fifth == 5)
		(pb(a, b), pb(a, b), sa(a), rra(a),
			pa(a, b), pa(a, b), ra(a), ra(a), ra(a));
	if (a[0]->next->next->content == 5 && fourth == 1 && fifth == 2)
		(ra(a), ra(a), ra(a));
	if (a[0]->next->next->content == 1 && fourth == 5 && fifth == 2)
		(ra(a), ra(a), sa(a), ra(a));
	if (a[0]->next->next->content == 1 && fourth == 5 && fifth == 4)
		(pb(a, b), rra(a), pb(a, b), rra(a),
			pa(a, b), pa(a, b), rra(a), rra(a), sa(a));
	if (a[0]->next->next->content == 5 && fourth == 2 && fifth == 1)
		(rra(a), rra(a), sa(a));
	if (a[0]->next->next->content == 2 && fourth == 5 && fifth == 1)
		(pb(a, b), pb(a, b), rra(a), rra(a),
			pa(a, b), pa(a, b), ra(a), ra(a), ra(a));
	if (a[0]->next->next->content == 5 && fourth == 4 && fifth == 1)
		(sa(a), rra(a), rra(a), rra(a), sa(a), ra(a), ra(a));
}

void	four_five_sort(t_list **a_stack, t_list **b_stack)
{
	if (ft_lstsize(a_stack[0]) == 5)
		specific_cases(a_stack, b_stack);
	if (!stack_sorted(a_stack[0]))
		real_four_five_sort(a_stack, b_stack);
}

void	three_sort(t_list **stack_a)
{
	t_list	*biggest_node;

	biggest_node = find_biggest(*stack_a);
	if (*stack_a == biggest_node)
		ra(stack_a);
	else if ((*stack_a)->next == biggest_node)
		rra(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
}

void	radix_sort(t_list **a_stack, t_list **b_stack)
{
	size_t	size;
	int		max_bit_len;
	int		i;

	size = find_biggest(a_stack[0])->index;
	max_bit_len = 0;
	while (size >> max_bit_len)
		max_bit_len++;
	i = 0;
	while (i < max_bit_len)
	{
		size = ft_lstsize(a_stack[0]);
		while (size--)
		{
			if ((a_stack[0]->index >> i) & 1)
				ra(a_stack);
			else
				pb(a_stack, b_stack);
		}
		while (ft_lstsize(b_stack[0]))
			pa(a_stack, b_stack);
		i++;
	}
}