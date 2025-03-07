/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:23:07 by duandrad          #+#    #+#             */
/*   Updated: 2025/03/07 01:35:43 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h" 

static	long	ft_atol(char *str)
{
	long	nbr;
	size_t	i;
	int		sign;

	nbr = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}

int	get_position(t_list **stack, int number)
{
	t_list	*curr;
	int		i;

	i = 0;
	curr = *stack;
	while (curr)
	{
		if (curr->content < number)
			i++;
		curr = curr->next;
	}
	return (i);
}

void	process_index(t_list **a)
{
	t_list	*curr;

	curr = *a;
	while (curr)
	{
		curr->index = get_position(a, curr->content);
		curr = curr->next;
	}
}

void	init_stack(t_list **a, char **av)
{
	long	nbr;
	int		i;

	i = -1;
	while (av[++i])
	{
		if (error_syn(av[i]))
		{
			ft_fputstr("Syntax Error\n", 1);
			free_error(a);
		}
		nbr = ft_atol(av[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
		{
			ft_fputstr("Invalid Number Error\n", 1);
			free_error(a);
		}
		if (error_rep(*a, nbr))
		{
			ft_fputstr("Repeated Number Error\n", 1);
			free_error(a);
		}
		ft_lstadd_back(a, ft_lstnew(nbr));
	}
	process_index(a);
}
