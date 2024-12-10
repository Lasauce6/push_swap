/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:55:43 by rbaticle          #+#    #+#             */
/*   Updated: 2024/12/10 12:13:41 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_element	*get_target(t_list *stack_a, t_list *stack_b)
{
	int			pos;
	t_element	*target;
	t_element	*e;

	pos = 0;
	target = malloc(sizeof(t_element));
	if (!target)
		return (0);
	target->element = stack_b;
	target->pos = pos;
	e = get_e_above(stack_a->content, stack_b);
	if (!e)
		return (free(target), NULL);
	while (stack_b && (e->pos != -1 || e->pos != pos - 1))
	{
		stack_b = stack_b->next;
		free(e);
		e = get_e_above(stack_a->content, stack_b);
		if (!e)
			return (free(target), NULL);
		pos++;
	}
	target->element = stack_b;
	target->pos = pos;
	return (free(e), target);
}

static void	next_element_iter_stack_friend(t_list **stack_a, int *pos)
{
	*stack_a = (*stack_a)->next;
	(*pos)++;
}

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
		target = get_target(stack_a, stack_b);
		if (!target)
			return (1);
		cost = get_cost(target->pos, pos, size_a, ft_lstsize(stack_b));
		if (cost < (*best_element)->cost)
		{
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
