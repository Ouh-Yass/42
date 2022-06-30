/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:29:11 by youhnia           #+#    #+#             */
/*   Updated: 2016/09/30 14:45:58 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (s && f)
	{
		i = -1;
		str = (char *)ft_memalloc(sizeof(char) * (ft_strlen((char *)s) + 1));
		if (str == NULL)
			return (NULL);
		while (s[++i])
			str[i] = f(i, (char)s[i]);
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
