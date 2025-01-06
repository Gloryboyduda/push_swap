/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:51:41 by duandrad          #+#    #+#             */
/*   Updated: 2025/01/06 15:22:37 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

typedef struct s_node
{
	int cost;
	int above_median;
	int cheapest;
	int position;
	int value;
	struct s_list *previous;
	struct s_list *next;
}	t_node;

void	ft_lstadd_back(t_node **lst, t_node *new);
void	ft_lstadd_front(t_node **lst, t_node *new);
void	ft_lstclear(t_node **lst, void (*del)(int));
void	ft_lstdelone(t_node *lst, void (*del)(int));
void	ft_lstiter(t_node *lst, void (*f)(int));
t_node	*ft_lstlast(t_node *lst);
t_node	*ft_lstmap(t_node *lst, void *(*f)(int), void (*del)(int));
t_node	*ft_lstnew(int value);
int	ft_lstsize(t_node *lst);
void sa(t_node **stack_a);
void sb(t_node **stack_b);
void ss(t_node **stack_a, t_node **stack_b);
t_node **init_stack(t_node **stack, char **av);
size_t	ft_strlen(char *str);
char	**ft_split(char *str, char delm);

#endif