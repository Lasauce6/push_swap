/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:04:24 by rbaticle          #+#    #+#             */
/*   Updated: 2024/12/10 12:13:15 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	swap_both(t_list **stack_a, t_list **stack_b)
{
	if (swap(stack_a, NO_PRINT))
		return (1);
	if (swap(stack_b, NO_PRINT))
	{
		swap(stack_a, NO_PRINT);
		return (1);
	}
	write(1, "ss\n", 3);
	return (0);
}

int	rotate_both(t_list **stack_a, t_list **stack_b)
{
	if (rotate(stack_a, NO_PRINT))
		return (1);
	if (rotate(stack_b, NO_PRINT))
	{
		reverse_rotate(stack_a, NO_PRINT);
		return (1);
	}
	write(1, "rr\n", 3);
	return (0);
}

int	reverse_rotate_both(t_list **stack_a, t_list **stack_b)
{
	if (reverse_rotate(stack_a, NO_PRINT))
		return (1);
	if (reverse_rotate(stack_b, NO_PRINT))
	{
		rotate(stack_a, NO_PRINT);
		return (1);
	}
	write(1, "rrr\n", 4);
	return (0);
}
