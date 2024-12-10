/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:47:22 by rbaticle          #+#    #+#             */
/*   Updated: 2024/12/10 12:13:22 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sort_2_elements(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		swap(stack_a, PRINT_A);
	return (0);
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

static int	sort_4_elements(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a, PRINT_B);
	sort_3_elements(stack_a);
	// TODO: push back to a
	return (0);
}

static int	sort_more_elements(t_list **stack_a, t_list **stack_b)
{
	t_best_e	*element;

	push(stack_b, stack_a, PRINT_B);
	push(stack_b, stack_a, PRINT_B);
	while (ft_lstsize(*stack_a) > 3)
	{
		element = get_best_element(*stack_a, *stack_b);
		if (!element)
			return (1);
		push(stack_b, stack_a, PRINT_B);
		//TODO: push to b
		free(element->target);
		free(element);
	}
	sort_3_elements(stack_a);
	// TODO: push back to a
	return (0);
}

int	sort_stacks(t_list **stack_a, t_list **stack_b)
{
	if (!is_sorted(*stack_a))
	{
		if (ft_lstsize(*stack_a) == 2)
			return (sort_2_elements(stack_a));
		if (ft_lstsize(*stack_a) == 3)
			return (sort_3_elements(stack_a));
		if (ft_lstsize(*stack_a) == 4)
			return (sort_4_elements(stack_a, stack_b));
		else
			return (sort_more_elements(stack_a, stack_b));
	}
	else
		return (0);
}
