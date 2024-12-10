/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:47:22 by rbaticle          #+#    #+#             */
/*   Updated: 2024/12/09 21:49:56 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO: Func to sort 3 and 2 elements

int	sort_2_elements(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		swap(stack_a, PRINT_A);
	return (0);
}

static int	get_stack_max_pos(t_list **stack)
{
	t_element	*e;
	int			max;

	e = get_stack_max(*stack);
	max = e->pos;
	free(e);
	return (max);
}

static int	get_stack_min_pos(t_list **stack)
{
	t_element	*e;
	int			min;

	e = get_stack_min(*stack);
	min = e->pos;
	free(e);
	return (min);
}

int	sort_3_elements(t_list **stack_a)
{
	if (get_stack_max_pos(stack_a) == 2)
		return (sort_2_elements(stack_a));
	else if (get_stack_max_pos(stack_a) == 1)
	{
		if (get_stack_min_pos(stack_a) == 0)
		{
			swap(stack_a, PRINT_A);
			rotate(stack_a, PRINT_A);
		}
		else
			rotate(stack_a, PRINT_A);
	}
	else
	{
		if (get_stack_min_pos(stack_a) == 1)
			rotate(stack_a, PRINT_A);
		else
		{
			swap(stack_a, PRINT_A);
			reverse_rotate(stack_a, PRINT_A);
		}
	}
	return (0);
}

int	sort_stacks(t_list **stack_a, t_list **stack_b)
{
	t_element	*element;

	if (ft_lstsize(*stack_a) == 1)
		return (0);
	if (ft_lstsize(*stack_a) == 2)
		return (sort_2_elements(stack_a));
	if (ft_lstsize(*stack_a) == 3)
		return (sort_3_elements(stack_a));
	else
	{
		push(stack_b, stack_a, PRINT_B);
		push(stack_b, stack_a, PRINT_B);
		while (ft_lstsize(*stack_a) > 3)
		{
			element = get_best_element(*stack_a, *stack_b);
			if (!element)
				return (1);
			//TODO: push to b
			free(element);
		}
		/*sort_3_elements(stack_a);*/
		// TODO: push back to a
	}
	return (0);
}
