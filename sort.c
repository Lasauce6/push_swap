/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:47:22 by rbaticle          #+#    #+#             */
/*   Updated: 2024/12/02 19:17:03 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_stacks(t_list *stack_a, t_list *stack_b)
{
	push(&stack_b, &stack_a, 'b');
	push(&stack_b, &stack_a, 'b');
	return (0);
}
