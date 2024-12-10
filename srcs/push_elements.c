/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:20:40 by rbaticle          #+#    #+#             */
/*   Updated: 2024/12/10 14:39:01 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push_to_b(t_list **stack_a, t_list **stack_b, t_best_e *e)
{
	if (e->target->pos >= ft_lstsize(*stack_b) / 2
		&& e->pos >= ft_lstsize(*stack_a) / 2)
	{
		while (e->target->pos < ft_lstsize(*stack_b)
			|| e->pos < ft_lstsize(*stack_a))
		{
			e->target->pos++;
			e->pos++;
			reverse_rotate_both(stack_a, stack_b);
		}
		while (e->target->pos++ < ft_lstsize(*stack_b))
			reverse_rotate(stack_b, PRINT_B);
		while (e->pos++ < ft_lstsize(*stack_a))
			reverse_rotate(stack_a, PRINT_A);
	}
	else if (e->target->pos < ft_lstsize(*stack_b) / 2
		&& e->pos < ft_lstsize(*stack_a) / 2)
	{
		while (e->target->pos > 0 || e->pos > 0)
		{
			e->target->pos--;
			e->pos--;
			rotate_both(stack_a, stack_b);
		}
		while (e->target->pos-- > 0)
			rotate(stack_b, PRINT_B);
		while (e->pos-- > 0)
			rotate(stack_a, PRINT_A);
	}
	else if (e->target->pos >= ft_lstsize(*stack_b) / 2
		&& e->pos < ft_lstsize(*stack_a) / 2)
	{
		while (e->target->pos++ < ft_lstsize(*stack_b))
			rotate(stack_b, PRINT_B);
		while (e->pos-- > 0)
			reverse_rotate(stack_a, PRINT_A);
	}
	else if (e->target->pos < ft_lstsize(*stack_b) / 2
		&& e->pos >= ft_lstsize(*stack_a) / 2)
	{
		while (e->target->pos-- > 0)
			reverse_rotate(stack_b, PRINT_B);
		while (e->pos++ <= ft_lstsize(*stack_a))
			rotate(stack_a, PRINT_A);
	}
	push(stack_b, stack_a, PRINT_B);
	return (0);
}
