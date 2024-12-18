/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:20:40 by rbaticle          #+#    #+#             */
/*   Updated: 2024/12/18 14:36:37 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_to_b_t_e_above_size(t_list **stack_a, t_list **stack_b,
									t_best_e *e)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	while (e->pos_target < size_a && e->pos < size_b)
	{
		e->pos_target++;
		e->pos++;
		reverse_rotate_both(stack_b, stack_a, PRINT);
	}
	while (e->pos_target++ < size_a)
		reverse_rotate(stack_a, PRINT_A);
	while (e->pos++ < size_b)
		reverse_rotate(stack_b, PRINT_B);
}

static void	push_to_b_t_e_bellow_size(t_list **stack_a, t_list **stack_b,
									t_best_e *e)
{
	while (e->pos_target > 0 && e->pos > 0)
	{
		e->pos_target--;
		e->pos--;
		rotate_both(stack_b, stack_a, PRINT);
	}
	while (e->pos_target-- > 0)
		rotate(stack_a, PRINT_A);
	while (e->pos-- > 0)
		rotate(stack_b, PRINT_B);
}

int	push_to_a(t_list **stack_a, t_list **stack_b, t_best_e *e)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	if (e->pos_target > size_a / 2 && e->pos > size_b / 2)
		push_to_b_t_e_above_size(stack_a, stack_b, e);
	else if (e->pos_target <= size_a / 2 && e->pos <= size_b / 2)
		push_to_b_t_e_bellow_size(stack_a, stack_b, e);
	else if (e->pos_target > size_a / 2 && e->pos <= size_b / 2)
	{
		while (e->pos_target++ < size_a)
			reverse_rotate(stack_a, PRINT_A);
		while (e->pos-- > 0)
			rotate(stack_b, PRINT_B);
	}
	else
	{
		while (e->pos_target-- > 0)
			rotate(stack_a, PRINT_A);
		while (e->pos++ < size_b)
			reverse_rotate(stack_b, PRINT_B);
	}
	push(stack_a, stack_b, PRINT_A);
	return (0);
}

int	push_to_b(t_list **stack_a, t_list **stack_b, int mediane)
{
	while (ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->content < mediane)
		{
			push(stack_b, stack_a, PRINT_B);
			rotate(stack_b, PRINT_B);
		}
		else
			push(stack_b, stack_a, PRINT_B);
	}
	return (0);
}

int	rotate_a(t_list **stack_a)
{
	if (get_stack_min_pos(*stack_a) > ft_lstsize(*stack_a) / 2)
	{
		while (get_stack_min_pos(*stack_a) != 0)
			reverse_rotate(stack_a, PRINT_A);
	}
	else
	{
		while (get_stack_min_pos(*stack_a) != 0)
			rotate(stack_a, PRINT_A);
	}
	return (0);
}
