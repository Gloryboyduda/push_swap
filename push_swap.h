/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:51:41 by duandrad          #+#    #+#             */
/*   Updated: 2025/03/04 19:23:25 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

/* error checking */
int		error_syn(char *str_n);
int		error_rep(t_list *a, int n);
void	free_stack(t_list **stack);
void	free_error(t_list **a);
char	**check_args(int ac, char **av);

/* initialization */
void	init_stack(t_list **stack, char **av);
char	**ft_split(char *str, char delm);

/* stack_utils */
bool	stack_sorted(t_list *stack);
void	ft_lstadd_back(t_list **lst, t_list *new_);
void	ft_lstadd_front(t_list **lst, t_list *new_);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
t_list	*find_smallest(t_list *stack);
t_list	*find_biggest(t_list *stack);
t_list	*ft_lstpenultimate(t_list *lst);

/* helpers */
void	ft_fputstr(char *str, int fd);
size_t	ft_strlen(char *str);

/* commands */
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_a);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

/* algorithm */
void	three_sort(t_list **stack_a);
void	check_algorithm(t_list **a, t_list **b);
void	odd_cases(t_list **a, t_list **b);
void	four_or_five(t_list **a_stack, t_list **b_stack);
void	radix_sort(t_list **a_stack, t_list **b_stack);

#endif