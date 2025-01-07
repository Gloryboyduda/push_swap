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

typedef struct s_node
{
	int cost;
	int above_median;
	int cheapest;
	int position;
	int value;
	struct s_node *previous;
	struct s_node *next;
}	t_node;

/* stack utils */
int	stack_size(t_node *stack);
t_node	*cheapest(t_node *stack);
t_node	*last_node(t_node *lst);
void	add_last(t_node **stack, int nbr);
t_node	*find_smallest(t_node *stack);

void sa(t_node **stack_a);
void sb(t_node **stack_b);
void ss(t_node **stack_a, t_node **stack_b);
void **init_stack(t_node **stack, char **av);
size_t	ft_strlen(char *str);
char	**ft_split(char *str, char delm);

#endif