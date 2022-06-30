/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 06:11:25 by youhnia           #+#    #+#             */
/*   Updated: 2016/04/06 09:45:32 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_itoa(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		n = n * -1;
	if (n == 0)
	{
		len = 1;
		return (len);
	}
	while (n >= 1)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static size_t	val_i(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		i = 1;
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = len_itoa(n);
	i = val_i(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)ft_memalloc((len + i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	str[len + 1] = '\0';
	while (len + i > i)
	{
		str[len - 1 + i] = (n % 10 + 48);
		n = n / 10;
		len--;
	}
	return (str);
}
