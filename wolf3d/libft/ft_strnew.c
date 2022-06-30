/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:36:27 by youhnia           #+#    #+#             */
/*   Updated: 2016/04/03 09:31:49 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *s;

	s = ft_memalloc(sizeof(char) * size + 1);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, ft_strlen(s));
	return (s);
}
