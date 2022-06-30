/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:25:33 by youhnia           #+#    #+#             */
/*   Updated: 2016/04/03 07:14:43 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		k;
	size_t	j;

	i = -1;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[++i] != '\0')
	{
		if (s2[0] == s1[i])
		{
			j = -1;
			k = i;
			while (s2[++j])
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
