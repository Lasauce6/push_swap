/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:00:38 by rbaticle          #+#    #+#             */
/*   Updated: 2024/12/10 12:14:00 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	add_to_stack(int element, t_list **stack)
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

int	parse_input(char **argv, t_list **stack_a)
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
		if (!parse_input(argv + 1, &stack_a))
		{
			ft_lstiter(stack_a, &ft_putnbr);
			write(1, "\n", 1);
			if (sort_stacks(&stack_a, &stack_b))
				ft_putstr_fd("Error\n", STDERR_FILENO);
			ft_lstiter(stack_a, &ft_putnbr);
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
