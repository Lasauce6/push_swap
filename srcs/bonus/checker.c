/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:50:33 by rbaticle          #+#    #+#             */
/*   Updated: 2024/12/18 15:26:18 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	free_stacks(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp;

	while (stack_a)
	{
		tmp = stack_a->next;
		free(stack_a);
		stack_a = tmp;
	}
	while (stack_b)
	{
		tmp = stack_b->next;
		free(stack_b);
		stack_b = tmp;
	}
}

static int	do_line(char *line, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(line, "pa\n", 3))
		push(stack_a, stack_b, NO_PRINT);
	else if (!ft_strncmp(line, "pb\n", 3))
		push(stack_b, stack_a, NO_PRINT);
	else if (!ft_strncmp(line, "ra\n", 3))
		rotate(stack_a, NO_PRINT);
	else if (!ft_strncmp(line, "rb\n", 3))
		rotate(stack_b, NO_PRINT);
	else if (!ft_strncmp(line, "rra\n", 4))
		reverse_rotate(stack_a, NO_PRINT);
	else if (!ft_strncmp(line, "rrb\n", 4))
		reverse_rotate(stack_b, NO_PRINT);
	else if (!ft_strncmp(line, "sa\n", 3))
		swap(stack_a, NO_PRINT);
	else if (!ft_strncmp(line, "sb\n", 3))
		swap(stack_b, NO_PRINT);
	else if (!ft_strncmp(line, "ss\n", 3))
		swap_both(stack_a, stack_b, NO_PRINT);
	else if (!ft_strncmp(line, "rr\n", 3))
		rotate_both(stack_a, stack_b, NO_PRINT);
	else if (!ft_strncmp(line, "rrr\n", 4))
		reverse_rotate_both(stack_a, stack_b, NO_PRINT);
	else
		return (1);
	return (0);
}

static int	read_stdin(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (do_line(line, stack_a, stack_b))
			return (1);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	if (line)
		free(line);
	if (is_sorted(*stack_a) && ft_lstsize(*stack_b) == 0)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = 0;
	stack_a = 0;
	if (argc > 1)
	{
		argv[argc] = 0;
		if (!parse_input(argv + 1, argc, &stack_a))
		{
			if (read_stdin(&stack_a, &stack_b))
				ft_putstr_fd("Error\n", STDERR_FILENO);
			free_stacks(stack_a, stack_b);
		}
		else
		{
			if (stack_a)
				ft_lstclear(&stack_a);
			ft_putstr_fd("Error\n", STDERR_FILENO);
			return (1);
		}
	}
	return (0);
}
