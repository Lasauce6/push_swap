/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:03:08 by rbaticle          #+#    #+#             */
/*   Updated: 2024/12/03 01:09:53 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

void	ft_putnbr(int n);
int		swap(t_list **stack, char c);
int		push(t_list **stack_to, t_list **stack_from, char c);
int		rotate(t_list **stack, char c);
int		reverse_rotate(t_list **stack, char c);
int		sort_stacks(t_list *stack_a, t_list *stack_b);
int		get_stack_max(t_list *stack);
int		get_stack_min(t_list *stack);

#endif
