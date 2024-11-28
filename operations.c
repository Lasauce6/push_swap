/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:23:08 by rbaticle          #+#    #+#             */
/*   Updated: 2024/11/28 14:58:18 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **stack)
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

int	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp;

	if (!*stack_from)
		return (1);
	if (!*stack_to)
	{
		*stack_to = *stack_from;
		*stack_from = (*stack_to)->next;
		(*stack_to)->next = NULL;
	}
	else
	{
		tmp = (*stack_from)->next;
		ft_lstadd_front(stack_to, *stack_from);
		*stack_from = tmp;
	}
	return (0);
}

int	rotate(t_list **stack)
{
	t_list	*tmp;

	if (!*stack)
		return (1);
	ft_lstlast(*stack)->next = *stack;
	tmp = (*stack)->next;
	(*stack)->next = NULL;
	*stack = tmp;
	return (0);
}

int	reverse_rotate(t_list **stack)
{
	t_list	*prev_last;
	t_list	*tmp;

	if (!*stack)
		return (1);
	prev_last = *stack;
	while (prev_last->next->next)
		prev_last = prev_last->next;
	tmp = ft_lstlast(*stack);
	prev_last->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
	return (0);
}
