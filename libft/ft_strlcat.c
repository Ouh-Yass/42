/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:12:54 by youhnia           #+#    #+#             */
/*   Updated: 2016/04/06 10:00:43 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	y;
	size_t	x;

	i = 0;
	y = ft_strlen(dst);
	x = ft_strlen((char *)src);
	if (dstsize > y + 1)
	{
		while (i < (dstsize - y - 1))
		{
			dst[y + i] = (char)src[i];
			i++;
		}
		dst[y + i] = '\0';
	}
	if (dstsize >= y)
		return (y + x);
	return (x + dstsize);
}
