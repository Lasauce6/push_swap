/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:03:08 by rbaticle          #+#    #+#             */
/*   Updated: 2024/12/18 14:35:55 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define NO_PRINT '0'
# define PRINT_A 'a'
# define PRINT_B 'b'
# define PRINT '1'
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

typedef struct s_best_e
{
	int	pos;
	int	val;
	int	pos_target;
	int	val_target;
	int	cost;
}	t_best_e;

// Operations
int			swap(t_list **stack, char flag);
int			push(t_list **stack_to, t_list **stack_from, char flag);
int			rotate(t_list **stack, char flag);
int			reverse_rotate(t_list **stack, char flag);

// Operations 2
int			swap_both(t_list **stack_a, t_list **stack_b, int flag);
int			rotate_both(t_list **stack_a, t_list **stack_b, int flag);
int			reverse_rotate_both(t_list **stack_a, t_list **stack_b, int flag);

// Sort
int			sort_stacks(t_list **stack_a, t_list **stack_b);

// Push elements
int			push_to_b(t_list **stack_a, t_list **stack_b, int mediane);
int			push_to_a(t_list **stack_a, t_list **stack_b, t_best_e *e);
int			rotate_a(t_list **stack_a);

// Best_element
t_best_e	*get_best_element(t_list *stack_a, t_list *stack_b);

// Utils
void		ft_putnbr(int n);
t_element	*get_stack_max(t_list *stack);
t_element	*get_stack_min(t_list *stack);
t_element	*get_e_above(int val, t_list *stack);
t_element	*get_e_bellow(int val, t_list *stack);

// Utils 2
int			get_stack_max_pos(t_list *stack);
int			get_stack_min_pos(t_list *stack);
int			is_sorted(t_list *stack);
int			ft_max(int a, int b);
void		free_argv(char **argv);

// Get Mediane
int			get_mediane(t_list *stack);

// Parsing
int			parse_input(char **argv, int argc, t_list **stack_a);
#endif
