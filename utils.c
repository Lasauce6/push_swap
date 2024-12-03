/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:49:45 by rbaticle          #+#    #+#             */
/*   Updated: 2024/12/02 16:57:00 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr(int n)
{
	long	nb;
	char	c;

	nb = n;
	if (nb < 0)
	{
		write(STDOUT_FILENO, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		c = '0' + (nb % 10);
		write(STDOUT_FILENO, &c, 1);
	}
}

int	get_stack_max(t_list *stack)
{
	int	max;

	max = INT_MIN;
	while (stack)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}

int	get_stack_min(t_list *stack)
{
	int	min;

	min = INT_MAX;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}
