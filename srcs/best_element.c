/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:55:43 by rbaticle          #+#    #+#             */
/*   Updated: 2024/12/10 15:19:30 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_element	*get_target(int val_a, t_list *stack_b)
{
	t_element	*target;

	target = get_e_bellow(val_a, stack_b);
	if (!target)
		return (NULL);
	if (target->pos == -1)
	{
		free(target);
		target = get_stack_max(stack_b);
	}
	return (target);
}

static void	next_element_iter_stack_friend(t_list **stack_a, int *pos)
{
	*stack_a = (*stack_a)->next;
	(*pos)++;
}

#include <stdio.h>
static int	iter_stack(t_best_e **best_element, t_list *stack_a,
					t_list *stack_b, int size_a)
{
	t_element	*target;
	int			pos;
	int			cost;

	pos = 0;
	cost = 0;
	while (stack_a)
	{
		target = get_target(stack_a->content, stack_b);
		if (!target)
			return (1);
		printf("element : %d target pos %d pos %d size_a %d size_b %d\n", stack_a->content, target->pos, pos, size_a, ft_lstsize(stack_b));
		cost = get_cost(target->pos, pos, size_a, ft_lstsize(stack_b));
		printf("cost pos %d: %d\n", pos, cost);
		if (cost < (*best_element)->cost)
		{
			ft_lstiter(stack_b, &ft_putnbr);
			write(1, "\n", 1);
			ft_lstiter(stack_a, &ft_putnbr);
			printf("\ntarget : %d\ne->pos = %d\n", target->pos, pos);
			free((*best_element)->target);
			(*best_element)->element = stack_a;
			(*best_element)->pos = pos;
			(*best_element)->cost = cost;
			(*best_element)->target = target;
		}
		else
			free(target);
		next_element_iter_stack_friend(&stack_a, &pos);
	}
	return (0);
}

t_best_e	*get_best_element(t_list *stack_a, t_list *stack_b)
{
	t_best_e	*best_element;

	best_element = malloc(sizeof(t_best_e));
	if (!best_element)
		return (NULL);
	best_element->target = malloc(sizeof(t_element));
	if (!best_element->target)
		return (free(best_element), NULL);
	best_element->cost = INT_MAX;
	if (iter_stack(&best_element, stack_a, stack_b, ft_lstsize(stack_a)))
		return (free(best_element->target), free(best_element), NULL);
	return (best_element);
}
