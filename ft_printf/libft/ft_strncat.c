/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 07:42:08 by youhnia           #+#    #+#             */
/*   Updated: 2016/04/04 22:46:20 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	int		y;

	i = 0;
	y = ft_strlen(dest);
	while (i != n)
	{
		dest[y] = src[i];
		i++;
		y++;
	}
	dest[y] = '\0';
	return (dest);
}
