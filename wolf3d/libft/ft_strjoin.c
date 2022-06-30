/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:11:26 by youhnia           #+#    #+#             */
/*   Updated: 2016/09/30 15:59:29 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		y;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	y = 0;
	str = (char *)ft_memalloc(sizeof(char) * ((ft_strlen((char *)
	s1) + ft_strlen((char *)s2) + 1)));
	if (str == NULL)
		return (NULL);
	while (s1[++i])
	{
		str[y] = (char)s1[i];
		y++;
	}
	i = -1;
	while (s2[++i])
	{
		str[y] = (char)s2[i];
		y++;
	}
	str[y] = '\0';
	return (str);
}
