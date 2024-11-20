/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:00:38 by rbaticle          #+#    #+#             */
/*   Updated: 2024/11/20 13:51:11 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_to_stack(int element, t_list **stack)
{
	t_list	*tmp;

	if (!*stack)
	{
		*stack = ft_lstnew(element);
		if (!*stack)
			return (0);
	}
	else
	{
		tmp = ft_lstnew(element);
		if (!tmp)
			return (0);
		ft_lstadd_back(stack, tmp);
	}
	return (1);
}

int	parse_input(int argc, char **argv, t_list **stack_a)
{
	int	i;
	int	j;

	i = -1;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
		}
		if (!add_to_stack(ft_atoi(argv[i]), stack_a))
			return (1);
	}
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
		if (!parse_input(argc - 1, argv + 1, &stack_a))
			ft_lstiter(stack_a, &ft_putnbr);
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
