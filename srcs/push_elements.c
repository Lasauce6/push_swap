/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:20:40 by rbaticle          #+#    #+#             */
/*   Updated: 2024/12/12 13:20:57 by rbaticle         ###   ########.fr       */
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
	while (e->pos_target < size_b && e->pos < size_a)
	{
		e->pos_target++;
		e->pos++;
		reverse_rotate_both(stack_a, stack_b);
	}
	while (e->pos_target++ < size_b)
		reverse_rotate(stack_b, PRINT_B);
	while (e->pos++ < size_a)
		reverse_rotate(stack_a, PRINT_A);
}

static void	push_to_b_t_e_bellow_size(t_list **stack_a, t_list **stack_b,
									t_best_e *e)
{
	while (e->pos_target > 0 && e->pos > 0)
	{
		e->pos_target--;
		e->pos--;
		rotate_both(stack_a, stack_b);
	}
	while (e->pos_target-- > 0)
		rotate(stack_b, PRINT_B);
	while (e->pos-- > 0)
		rotate(stack_a, PRINT_A);
}

int	push_to_b(t_list **stack_a, t_list **stack_b, t_best_e *e)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	if (e->pos_target > size_b / 2 && e->pos > size_a / 2)
		push_to_b_t_e_above_size(stack_a, stack_b, e);
	else if (e->pos_target <= size_b / 2 && e->pos <= size_a / 2)
		push_to_b_t_e_bellow_size(stack_a, stack_b, e);
	else if (e->pos_target > size_b / 2 && e->pos <= size_b / 2)
	{
		while (e->pos_target++ < size_b)
			reverse_rotate(stack_b, PRINT_B);
		while (e->pos-- > 0)
			rotate(stack_a, PRINT_A);
	}
	else
	{
		while (e->pos_target-- > 0)
			rotate(stack_b, PRINT_B);
		while (e->pos++ < size_a)
			reverse_rotate(stack_a, PRINT_A);
	}
	push(stack_b, stack_a, PRINT_B);
	return (0);
}

int	push_back_to_a(t_list **stack_a, t_list **stack_b)
{
	t_element	*e_max;
	int			size_b;

	e_max = get_stack_max(*stack_b);
	if (!e_max)
		return (1);
	size_b = ft_lstsize(*stack_b);
	if (e_max->pos > size_b / 2)
	{
		while (e_max->pos-- > 0)
			rotate(stack_b, PRINT_B);
	}
	else
	{
		while (e_max->pos++ < size_b)
			reverse_rotate(stack_b, PRINT_B);
	}
	while (*stack_b)
		push(stack_a, stack_b, PRINT_A);
	free(e_max);
	return (0);
}
