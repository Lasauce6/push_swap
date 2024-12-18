/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:18:08 by rbaticle          #+#    #+#             */
/*   Updated: 2024/11/20 13:42:37 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f) (int))
{
	t_list	*new_lst;
	t_list	*e;

	new_lst = 0;
	if (!f)
		return (0);
	while (lst)
	{
		e = ft_lstnew(f(lst->content));
		if (!e)
		{
			ft_lstclear(&new_lst);
			return (0);
		}
		ft_lstadd_back(&new_lst, e);
		lst = lst->next;
	}
	return (new_lst);
}
