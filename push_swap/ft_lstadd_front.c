/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:09:04 by duarte            #+#    #+#             */
/*   Updated: 2025/01/06 15:32:30 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	new->next = *lst;
	*lst = new;
}
/* int main()
{
	t_node *new1;
	t_node *new2;

	new1= (t_node *)malloc(sizeof(t_node));
	if (!new1)
		return (-1);
	new2= (t_node *)malloc(sizeof(t_node));
	if (!new2)
		return (-1);
	new1->content = "string";
	new1->next = new2;
	new2->content = "ended";
	new2->next = NULL;
	t_node **head = &new1;
	t_node *new3;
	new3 = (t_node *)malloc(sizeof(t_node));
	if (!new3)
		return (-1);
	new3->content = "conteudo";
	new3->next = NULL;
	ft_lstadd_front(head, new3);
	return 0;
}
 */