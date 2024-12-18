/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mediane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:17:49 by rbaticle          #+#    #+#             */
/*   Updated: 2024/12/18 10:07:40 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	*fill_tab(t_list *stack, int stack_size)
{
	int	*tab;
	int	i;

	tab = malloc(sizeof(int) * stack_size);
	if (!tab)
		return (NULL);
	i = 0;
	while (stack)
	{
		tab[i] = stack->content;
		i++;
		stack = stack->next;
	}
	return (tab);
}

int	get_mediane(t_list *stack)
{
	int	*tab;
	int	i;
	int	j;
	int	tmp;

	tab = fill_tab(stack, ft_lstsize(stack));
	if (!tab)
		return (1);
	i = -1;
	while (++i < ft_lstsize(stack))
	{
		j = i + 1;
		while (++j < ft_lstsize(stack))
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
		}
	}
	return (free(tab), tab[ft_lstsize(stack) / 2]);
}
