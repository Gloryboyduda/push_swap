/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:02:28 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/19 17:19:30 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_list **dest, t_list**src)
{
	t_list	*push_node;

	if (!dest || !src || !*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	push_node->next = NULL;
	if (*dest)
		push_node->next = *dest;
	*dest = push_node;
}

void	pa(t_list **a, t_list **b)
{
	push(a, b);
	ft_fputstr("pa\n", 1);
}

void	pb(t_list **a, t_list **b)
{
	push(b, a);
	ft_fputstr("pb\n", 1);
}
