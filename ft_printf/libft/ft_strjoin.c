/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:11:26 by youhnia           #+#    #+#             */
/*   Updated: 2016/04/06 09:58:42 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		y;
	char	*str;

	i = 0;
	y = 0;
	str = (char *)ft_memalloc(sizeof(char) * ((ft_strlen((char *)
	s1) + ft_strlen((char *)s2) + 1)));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[y] = (char)s1[i];
		i++;
		y++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[y] = (char)s2[i];
		i++;
		y++;
	}
	str[y] = '\0';
	return (str);
}
