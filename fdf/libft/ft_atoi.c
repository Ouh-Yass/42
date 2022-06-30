/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 07:59:18 by youhnia           #+#    #+#             */
/*   Updated: 2016/04/06 09:42:22 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	verif(const char *nptr)
{
	int i;

	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	return (i);
}

int			ft_atoi(const char *nptr)
{
	int i;
	int num;

	i = verif(nptr);
	num = 0;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		num = (num * 10) + (nptr[i] - 48);
		i++;
	}
	if (nptr[i] < '0' && nptr[i] > '9')
		return (0);
	if (nptr[verif(nptr)] == '-')
		return (num * -1);
	return (num);
}
