/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:48:18 by rbaticle          #+#    #+#             */
/*   Updated: 2024/12/10 12:13:37 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_stack_max_pos(t_list **stack)
{
	t_element	*e;
	int			max;

	e = get_stack_max(*stack);
	max = e->pos;
	free(e);
	return (max);
}

int	get_stack_min_pos(t_list **stack)
{
	t_element	*e;
	int			min;

	e = get_stack_min(*stack);
	min = e->pos;
	free(e);
	return (min);
}

int	is_sorted(t_list *stack)
{
	if (ft_lstsize(stack) <= 1)
		return (1);
	while (stack <= stack->next)
		stack = stack->next;
	if (stack->next)
		return (0);
	return (1);
}

int	is_rev_sorted(t_list *stack)
{
	if (ft_lstsize(stack) <= 1)
		return (1);
	while (stack >= stack->next)
		stack = stack->next;
	if (stack->next)
		return (0);
	return (1);
}