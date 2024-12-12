/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:55:43 by rbaticle          #+#    #+#             */
/*   Updated: 2024/12/12 12:05:30 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_element	*get_target(int val_a, t_list *stack_b)
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

static int	get_cost(int t_pos, int e_pos, int size_a, int size_b)
{
	if (t_pos > size_b / 2 && e_pos > size_a / 2)
		return ((size_b - t_pos) + (size_a - e_pos) + 1);
	else if (t_pos <= size_b / 2 && e_pos <= size_a / 2)
		return (t_pos + e_pos + 1);
	else if (t_pos > size_b / 2)
		return ((size_b - t_pos) + e_pos + 1);
	else
		return (t_pos + (size_a - e_pos) + 1);
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
		target = get_target(stack_a->content, stack_b);
		if (!target)
			return (1);
		cost = get_cost(target->pos, pos, size_a, ft_lstsize(stack_b));
		if (cost < (*best_element)->cost)
		{
			(*best_element)->cost = cost;
			(*best_element)->val = stack_a->content;
			(*best_element)->pos = pos;
			(*best_element)->val_target = target->element->content;
			(*best_element)->pos_target = target->pos;
		}
		free(target);
		stack_a = stack_a->next;
		pos++;
	}
	return (0);
}

t_best_e	*get_best_element(t_list *stack_a, t_list *stack_b)
{
	t_best_e	*best_element;

	best_element = malloc(sizeof(t_best_e));
	if (!best_element)
		return (NULL);
	best_element->cost = INT_MAX;
	if (iter_stack(&best_element, stack_a, stack_b, ft_lstsize(stack_a)))
		return (free(best_element), NULL);
	return (best_element);
}
