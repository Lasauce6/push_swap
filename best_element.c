/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:55:43 by rbaticle          #+#    #+#             */
/*   Updated: 2024/12/09 21:28:00 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	get_cost(t_element *target, t_list *stack_a, t_element *e_to_push,
			t_list *stack_b)
{
	int	cost;
	int	t_pos;
	int	e_pos;

	cost = 0;
	t_pos = target->pos;
	e_pos = e_to_push->pos;
	if (t_pos > ft_lstsize(stack_b) / 2 && e_pos > ft_lstsize(stack_a) / 2)
	{

	}
	//TODO: GET THE COST
	return (cost);
}

static void	next_element_iter_stack_friend(t_list **stack_a,
		int *pos, t_element **target)
{
	*stack_a = (*stack_a)->next;
	(*pos)++;
	free(*target);
}

static int	iter_stack(t_element **best_element, t_list *stack_a,
						t_list *stack_b, t_element **e)
{
	t_element	*target;
	t_list		*stack_a_cpy;
	int			pos;
	int			cost;

	pos = 0;
	cost = 0;
	stack_a_cpy = stack_a;
	while (stack_a)
	{
		target = get_target(stack_a, stack_b);
		if (!target)
			return (1);
		(*e)->pos = pos;
		(*e)->element = stack_a;
		cost = get_cost(target, stack_a_cpy, *e, stack_b);
		if (cost < (*best_element)->cost)
		{
			(*best_element)->element = stack_a;
			(*best_element)->pos = pos;
			(*best_element)->cost = cost;
		}
		next_element_iter_stack_friend(&stack_a, &pos, &target);
	}
	return (0);
}

t_element	*get_best_element(t_list *stack_a, t_list *stack_b)
{
	t_element	*best_element;
	t_element	*e;

	best_element = malloc(sizeof(t_element));
	if (!best_element)
		return (NULL);
	best_element->cost = INT_MAX;
	e = malloc(sizeof(t_element));
	if (!e)
		return (free(best_element), NULL);
	if (!iter_stack(&best_element, stack_a, stack_b, &e))
		return (free(best_element), free(e), NULL);
	return (best_element);
}
