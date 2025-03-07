/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 03:28:01 by duandrad          #+#    #+#             */
/*   Updated: 2025/03/06 20:03:08 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	print_list(t_list **a)
{
	t_list	*currnt;

	currnt = *a;
	while (currnt)
	{
		printf("%d\n", currnt->content);
		currnt = currnt->next;
	}
} */

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
/* 	char	**checked_args;
	
	checked_args = NULL; */
	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	/* checked_args = check_args(ac, av); */
	init_stack(&a, av + 1);
	if (!stack_sorted(a))
	{
		if (ft_lstsize(a) == 2)
			sa(&a);
		else if (ft_lstsize(a) == 3)
			three_sort(&a);
		else if (ft_lstsize(a) == 4 || ft_lstsize(a) == 5)
			check_algorithm(&a, &b);
		else
			radix_sort(&a, &b);
	}
	free_stack(&a);
	free(b);
	return (0);
}
