/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:23:08 by rbaticle          #+#    #+#             */
/*   Updated: 2024/11/23 13:12:08 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
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
