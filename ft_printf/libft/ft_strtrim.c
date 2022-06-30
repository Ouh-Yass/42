/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 05:32:01 by youhnia           #+#    #+#             */
/*   Updated: 2016/04/06 10:08:57 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	start;
	size_t			len;

	start = 0;
	len = ft_strlen((char *)s) - 1;
	if (s == NULL)
		return (NULL);
	while (s[start] && (s[start] == ' ' ||
	s[start] == '\n' || s[start] == '\t'))
		start++;
	while (s[len] && (s[len] == ' ' || s[len] == '\n' || s[len] == '\t'))
		len--;
	len++;
	if (len == 0)
		return ("");
	str = ft_strsub(s, start, len - start);
	return (str);
}
