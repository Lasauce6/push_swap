/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:59:52 by rbaticle          #+#    #+#             */
/*   Updated: 2024/12/18 14:06:39 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		if (ft_strlen(argv[i]) > 11 || ft_strlen(argv[i]) == 0
			|| (ft_strlen(argv[i]) > 10 && ft_isdigit(argv[i][0])))
			return (0);
		j = -1;
		if (argv[i][0] == '-' || argv[i][0] == '+')
			j++;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
		}
		if ((argv[i][0] == '-' && ft_atoi(argv[i]) >= 0)
			|| (argv[i][0] != '-' && ft_atoi(argv[i]) < 0))
			return (0);
		if (add_to_stack(ft_atoi(argv[i]), stack_a))
			return (0);
	}
	return (i);
}

static int	check_dups(t_list *stack_a)
{
	t_list	*stack_i;
	t_list	*stack_j;

	stack_i = stack_a;
	while (stack_i)
	{
		stack_j = stack_i->next;
		while (stack_j)
		{
			if (stack_i->content == stack_j ->content)
				return (1);
			stack_j = stack_j->next;
		}
		stack_i = stack_i->next;
	}
	return (0);
}

int	parse_input(char **argv, int argc, t_list **stack_a)
{
	if (argc == 2)
		argv = ft_split(argv[0], ' ');
	if (!argv)
		return (1);
	if (check_argv(argv, stack_a) != argc - 1)
	{
		if (argc == 2)
			free_argv(argv);
		return (1);
	}
	if (check_dups(*stack_a))
	{
		if (argc == 2)
			free_argv(argv);
		return (1);
	}
	if (argc == 2)
		free_argv(argv);
	return (0);
}
