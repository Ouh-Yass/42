/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 07:12:16 by youhnia           #+#    #+#             */
/*   Updated: 2016/03/31 10:30:20 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int y;

	i = 0;
	y = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[y] = src[i];
		i++;
		y++;
	}
	dest[y] = '\0';
	return (dest);
}
