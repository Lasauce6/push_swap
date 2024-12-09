/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:47:22 by rbaticle          #+#    #+#             */
/*   Updated: 2024/12/09 18:48:59 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO: Func to sort 3 and 2 elements

int	sort_stacks(t_list **stack_a, t_list **stack_b)
{
	t_element	*element;

	if (ft_lstsize(*stack_a) == 1)
		return (0);
	/*if (ft_lstsize(*stack_a) == 2)*/
	/*	return (sort_2_elements(stack_a));*/
	/*if (ft_lstsize(*stack_a) == 3)*/
	/*	return (sort_3_elements(stack_a));*/
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
