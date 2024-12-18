/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:47:22 by rbaticle          #+#    #+#             */
/*   Updated: 2024/12/18 12:37:07 by rbaticle         ###   ########.fr       */
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
	if (get_stack_max_pos(*stack_a) == 2)
		return (sort_2_elements(stack_a));
	else if (get_stack_max_pos(*stack_a) == 1)
	{
		if (get_stack_min_pos(*stack_a) == 0)
		{
			swap(stack_a, PRINT_A);
			rotate(stack_a, PRINT_A);
		}
		else
			rotate(stack_a, PRINT_A);
	}
	else
	{
		if (get_stack_min_pos(*stack_a) == 1)
			rotate(stack_a, PRINT_A);
		else
		{
			swap(stack_a, PRINT_A);
			reverse_rotate(stack_a, PRINT_A);
		}
	}
	return (0);
}

static int	sort_more_elements(t_list **stack_a, t_list **stack_b)
{
	t_best_e	*element;
	int			mediane;

	mediane = get_mediane(*stack_a);
	while (ft_lstsize(*stack_a) > 3 && ft_lstsize(*stack_b) < 2)
		push(stack_b, stack_a, PRINT_B);
	push_to_b(stack_a, stack_b, mediane);
	sort_3_elements(stack_a);
	while (ft_lstsize(*stack_b) != 0)
	{
		element = get_best_element(*stack_a, *stack_b);
		if (!element)
			return (1);
		push_to_a(stack_a, stack_b, element);
		free(element);
	}
	rotate_a(stack_a);
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
		else
			return (sort_more_elements(stack_a, stack_b));
	}
	else
		return (0);
}
