/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 05:47:28 by youhnia           #+#    #+#             */
/*   Updated: 2016/03/31 14:22:29 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	char	*cp;
	int		i;

	cp = (char*)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (cp == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		cp[i] = s[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
