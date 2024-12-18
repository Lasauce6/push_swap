/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:00:38 by rbaticle          #+#    #+#             */
/*   Updated: 2024/12/18 13:41:19 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int	add_to_stack(int element, t_list **stack)
{
	t_list	*tmp;

	if (!*stack)
	{
		*stack = ft_lstnew(element);
		if (!*stack)
			return (1);
	}
	else
	{
		tmp = ft_lstnew(element);
		if (!tmp)
			return (1);
		ft_lstadd_back(stack, tmp);
	}
	return (0);
}

static int	check_argv(char **argv, t_list **stack_a)
{
	int	i;
	int	j;

	i = -1;
	while (argv[++i])
	{
		if (ft_strlen(argv[i]) > 11
			|| (ft_strlen(argv[i]) > 10 && ft_isdigit(argv[i][0])))
			return (1);
		j = -1;
		if (argv[i][0] == '-' || argv[i][0] == '+')
			j++;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
		}
		if ((argv[i][0] == '-' && ft_atoi(argv[i]) >= 0)
			|| (argv[i][0] != '-' && ft_atoi(argv[i]) < 0))
			return (1);
		if (add_to_stack(ft_atoi(argv[i]), stack_a))
			return (1);
	}
	return (0);
}

static int	parse_input(char **argv, int argc, t_list **stack_a)
{
	t_list	*stack_i;
	t_list	*stack_j;

	if (argc == 2)
		argv = ft_split(argv[0], ' ');
	if (check_argv(argv, stack_a))
		return (free_argv(argv), 1);
	stack_i = *stack_a;
	while (stack_i)
	{
		stack_j = stack_i->next;
		while (stack_j)
		{
			if (stack_i->content == stack_j ->content)
				return (free_argv(argv), 1);
			stack_j = stack_j->next;
		}
		stack_i = stack_i->next;
	}
	if (argc == 2)
		free_argv(argv);
	return (0);
}

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
			if (sort_stacks(&stack_a, &stack_b))
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
