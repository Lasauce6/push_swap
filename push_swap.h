/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:03:08 by rbaticle          #+#    #+#             */
/*   Updated: 2024/12/06 17:11:37 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define NO_PRINT '0'
# define PRINT_A 'a'
# define PRINT_B 'b'
# define SWAP 1
# define PUSH 2
# define ROTATE 3
# define REVERSE_ROTATE 4

typedef struct s_element
{
	int		cost;
	int		pos;
	t_list	*element;
}	t_element;

void		ft_putnbr(int n);

// Operations
int			swap(t_list **stack, char flag);
int			push(t_list **stack_to, t_list **stack_from, char flag);
int			rotate(t_list **stack, char flag);
int			reverse_rotate(t_list **stack, char flag);
// Operations 2
int			swap_both(t_list **stack_a, t_list **stack_b);
int			rotate_both(t_list **stack_a, t_list **stack_b);
int			reverse_rotate_both(t_list **stack_a, t_list **stack_b);

// Sort
int			sort_stacks(t_list **stack_a, t_list **stack_b);

// Best_element
t_element	*get_target(t_list *stack_a, t_list *stack_b);
t_element	*get_best_element(t_list *stack_a, t_list *stack_b);

// Utils
t_element	*get_stack_max(t_list *stack);
t_element	*get_stack_min(t_list *stack);
t_element	*get_e_above(int val, t_list *stack);
t_element	*get_e_bellow(int val, t_list *stack);

#endif
