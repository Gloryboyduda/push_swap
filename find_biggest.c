/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:45:05 by duandrad          #+#    #+#             */
/*   Updated: 2025/01/06 15:32:30 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	biggest_value(t_node **list)
{
	t_node *head;
	int top;

	head = *list;
	top = head->value;
	while (head->next != NULL)
	{
		if (top < head->next->value)
			top = head->next->value;
		head = head->next;
	}
	return (top);
}
