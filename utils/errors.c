/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:25:58 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/19 19:02:13 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	error_syn(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	str++;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
		str++;
	}	return (0);
}

int	error_rep(t_list *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->content == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;
	t_list	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_error(t_list **a)
{
	free_stack(a);
	ft_fputstr("Error\n", 1);
	exit(1);
}

char	**check_args(int ac, char **av)
{
	char	**args;
	
	args = NULL;
	if (ac < 2)
		ft_fputstr("Invalid Number of Arguments\n", 1);
	if (ac == 2)
	{
		args = ft_split(*av + 1, ' ');
		if (!args || *args)
		{
			ft_fputstr("Split Error\n", 1);
			free(args);
		}
		av = args;
	}
	return (av);
}