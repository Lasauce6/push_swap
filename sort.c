/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:47:22 by rbaticle          #+#    #+#             */
/*   Updated: 2024/12/04 14:09:08 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*get_target(t_list *stack_a, t_list *stack_b)
{
	t_element	*target;

	target = 0;
	if (get_e_above(stack_a->content, stack_b)->pos == 0
		|| get_e_above(stack_a->content, stack_b)->pos == ft_lstsize(stack_b))
		return (target);
	while (stack_b && stack_a->content > stack_b->content)
	{
		// TODO: get the target position in stack_b for stack_a element
	}
	return (target);
}

t_list	*get_best_element(t_list *stack_a, t_list *stack_b)
{
	t_list		*best_element;
	t_element	*target;
	int			pos;
	int			cost;
	int			temp_cost;

	pos = 0;
	cost = 0;
	while (stack_a)
	{
		target = get_target(stack_a, stack_b);
		if (temp_cost < cost)
			best_element = stack_a;
		stack_a = stack_a->next;
		pos++;
	}
	return (best_element);
}

void	sort_3_elements(t_list **stack_a)
{
	// TODO: sort the 3 last elements
}

int	sort_stacks(t_list **stack_a, t_list **stack_b)
{
	t_list	*element;

	if (ft_lstsize(*stack_a) < 3)
	{
		sort_3_elements(stack_a);
		return (0);
	}
	push(stack_b, stack_a, PRINT_B);
	push(stack_b, stack_a, PRINT_B);
	while (ft_lstsize(*stack_a) > 3)
	{
		element = get_best_element(*stack_a, *stack_b);
	}
	return (0);
}
