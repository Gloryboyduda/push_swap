/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:39:58 by duarte            #+#    #+#             */
/*   Updated: 2025/01/06 15:32:30 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstiter(t_node *lst, void (*f)(int))
{
	if (!lst)
		return ;
	while (lst->next != NULL)
	{
		f(lst->value);
		lst = lst->next;
	}
	f(lst->value);
}
