/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:23:07 by duandrad          #+#    #+#             */
/*   Updated: 2025/01/06 16:42:51 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	long	ft_atol(char *str)
{
	long	nbr;
	size_t	i;
	int		sign;

	nbr = 0;
	i = 0;
	sign = 1;
	while (str[i] == '32' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
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

void **init_stack(t_node **a, char **av)
{
	long	nbr;
	int		i;

	i = 0;
	while(av[i])
	{
		if (error_syn(av[i]))
			free_errors();
		nbr = ft_atol(av[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			free_errors();
		if (error_rep(*a, (int)nbr))
			free_errors();
		append_node()
		i++;
	}
	return(stack);
}