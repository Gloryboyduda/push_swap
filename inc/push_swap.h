/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:51:41 by duandrad          #+#    #+#             */
/*   Updated: 2025/01/13 12:59:20 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				position;
	int				push_price;
	int				above_median;
	int				cheapest;
	struct s_node	*target_node;
	struct s_node	*previous;
	struct s_node	*next;
}	t_node;

/* error checking */
int		error_syn(char *str_n); 
int		error_rep(t_node *a, int n);
void	free_stack(t_node **stack);
void	free_error(t_node **a);

/* initialization */
void **init_stack(t_node **stack, char **av);
char	**ft_split(char *str, char delm);

/* stacks */
int		stack_size(t_node *stack);
t_node	*last_node(t_node *lst);
int		stack_sorted(t_node *stack);
t_node	*find_smallest(t_node *stack);
t_node	*find_biggest(t_node *stack);


void	init_nodes(t_node *a, t_node *b);
void	set_target_node(t_node *a, t_node *b);

/* node utils */
void	init_nodes_a(t_node *a, t_node *b);
void	init_nodes_b(t_node *a, t_node *b);
void	set_current_position(t_node *stack);
void	set_cheapest(t_node *b);
t_node	*cheapest(t_node *stack);
void	prep_for_push(t_node **s, t_node *n, char c);
void	add_last(t_node **stack, int nbr);
size_t	ft_strlen(char *str);

/* commands */
void sa(t_node **stack_a);
void sb(t_node **stack_b);
void ss(t_node **stack_a, t_node **stack_b);



#endif