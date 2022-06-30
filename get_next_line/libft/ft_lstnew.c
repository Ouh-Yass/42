/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 13:38:29 by youhnia           #+#    #+#             */
/*   Updated: 2016/04/07 09:40:39 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*cp;

	new = (t_list*)ft_memalloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	if (content == 0)
	{
		content = NULL;
		content_size = 0;
	}
	else
	{
		cp = ft_memalloc(sizeof(content_size));
		if (cp == NULL)
		{
			ft_memdel((void *)new);
			return (NULL);
		}
		new->content = ft_memcpy(cp, content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
