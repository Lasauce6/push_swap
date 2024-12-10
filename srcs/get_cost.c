/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:36:25 by rbaticle          #+#    #+#             */
/*   Updated: 2024/12/10 16:26:17 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_cost_t_e_above_size(int t_pos, int e_pos, int size_a,
								int size_b)
{
	int	cost;

	cost = 0;
	while (t_pos < size_b || e_pos < size_a)
	{
		t_pos++;
		e_pos++;
		cost++;
	}
	while (t_pos++ < size_b)
		cost++;
	while (e_pos++ < size_a)
		cost++;
	return (cost + 1);
}

static int	get_cost_t_e_bellow_size(int t_pos, int e_pos)
{
	int	cost;

	cost = 0;
	while (t_pos > 0 || e_pos > 0)
	{
		t_pos--;
		e_pos--;
		cost++;
	}
	while (t_pos-- > 0)
		cost++;
	while (e_pos-- > 0)
		cost++;
	return (cost + 1);
}

int	get_cost(int t_pos, int e_pos, int size_a, int size_b)
{
	int	cost;

	cost = 0;
	if (t_pos >= size_b / 2 && e_pos >= size_a / 2)
		return (get_cost_t_e_above_size(t_pos, e_pos, size_a, size_b));
	else if (t_pos < size_b / 2 && e_pos < size_a / 2)
		return (get_cost_t_e_bellow_size(t_pos, e_pos));
	else if (t_pos >= size_b / 2 && e_pos < size_a / 2)
	{
		while (t_pos++ < size_b)
			cost++;
		while (e_pos-- > 0)
			cost++;
		return (cost + 1);
	}
	while (t_pos-- > 0)
		cost++;
	while (e_pos++ <= size_a)
		cost++;
	return (cost + 1);
}
