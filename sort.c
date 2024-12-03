/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:47:22 by rbaticle          #+#    #+#             */
/*   Updated: 2024/12/03 15:38:25 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_best_element(t_list *stack_a, t_list *stack_b)
{
}

int	sort_stacks(t_list *stack_a, t_list *stack_b)
{
	t_list	*element;

	push(&stack_b, &stack_a, PRINT_B);
	push(&stack_b, &stack_a, PRINT_B);
	while (ft_lstsize(stack_a) > 3)
	{
		element = get_best_element(stack_a, stack_b);
	}
	return (0);
}
