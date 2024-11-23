/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:23:08 by rbaticle          #+#    #+#             */
/*   Updated: 2024/11/23 12:35:43 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list	**stack)
{
	t_list	*tmp;

	if (!*stack || !(*stack)->next)
		return (1);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	return (0);
}

int	push(t_list	**stack_to, t_list **stack_from)
{
	if (!*stack_from)
		return (1);

	return (0);
}
