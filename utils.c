/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:49:45 by rbaticle          #+#    #+#             */
/*   Updated: 2024/12/05 15:15:12 by rbaticle         ###   ########.fr       */
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

t_element	*get_stack_max(t_list *stack)
{
	int			max;
	int			pos;
	t_element	*e;

	max = INT_MIN;
	pos = 0;
	e = 0;
	while (stack)
	{
		if (stack->content > max)
		{
			max = stack->content;
			e->pos = pos;
			e->element = stack;
		}
		stack = stack->next;
		pos++;
	}
	return (e);
}

t_element	*get_stack_min(t_list *stack)
{
	int			min;
	int			pos;
	t_element	*e;

	min = INT_MAX;
	pos = 0;
	e = 0;
	while (stack)
	{
		if (stack->content < min)
		{
			min = stack->content;
			e->pos = pos;
			e->element = stack;
		}
		stack = stack->next;
		pos++;
	}
	return (e);
}

t_element	*get_e_above(int val, t_list *stack)
{
	int			pos;
	int			min;
	t_element	*e;

	min = INT_MAX;
	pos = 0;
	e = malloc(sizeof(t_element));
	if (!e)
		return (NULL);
	e->pos = -1;
	while (stack)
	{
		if (stack->content > val && val < min)
		{
			min = stack->content;
			e->pos = pos;
			e->element = stack;
		}
		stack = stack->next;
		pos++;
	}
	return (e);
}

t_element	*get_e_bellow(int val, t_list *stack)
{
	int			pos;
	int			max;
	t_element	*e;

	max = INT_MIN;
	pos = 0;
	e = malloc(sizeof(t_element));
	if (!e)
		return (NULL);
	e->pos = -1;
	while (stack)
	{
		if (stack->content < val && val > max)
		{
			max = stack->content;
			e->pos = pos;
			e->element = stack;
		}
		stack = stack->next;
		pos++;
	}
	return (e);
}
