/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 15:18:42 by youhnia           #+#    #+#             */
/*   Updated: 2016/04/08 15:30:51 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *first;
	t_list *new;

	first = (t_list *)ft_memalloc(sizeof(t_list));
	if (first && lst)
	{
		first = f(lst);
		new = (t_list *)ft_memalloc(sizeof(t_list));
		if (new)
		{
			new = first;
			lst = lst->next;
			while (lst != NULL)
			{
				new->next = f(lst);
				new = new->next;
				lst = lst->next;
			}
			return (first);
		}
	}
	return (NULL);
}
