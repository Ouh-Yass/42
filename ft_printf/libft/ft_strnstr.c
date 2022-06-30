/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:37:15 by youhnia           #+#    #+#             */
/*   Updated: 2016/04/06 10:05:58 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	k;
	size_t	j;

	i = -1;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (++i < n && s1[i])
	{
		if (s2[0] == s1[i])
		{
			j = -1;
			k = i;
			while (s2[++j] && k < n)
			{
				if (s2[j] == s1[k])
					k++;
				else
					break ;
			}
			if (s2[j] == '\0')
				return ((char *)&s1[i]);
		}
	}
	return (NULL);
}
