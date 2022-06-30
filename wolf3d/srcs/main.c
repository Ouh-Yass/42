/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <youhnia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:03:47 by youhnia           #+#    #+#             */
/*   Updated: 2017/03/06 18:03:47 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			main(int argc, char *argv[])
{
	t_env	*e;
	int		i;

	if (argc != 1 && argv[1])
	{
		ft_putstr("usage : only ./wolf3d\n");
		return (-1);
	}
	if ((e = (t_env *)ft_memalloc(sizeof(t_env))) == NULL)
		return (-1);
	init_env(e);
	ft_creat_tab(e);
	i = -1;
	while (e->map[++i])
		i++;
	loop(e);
	return (0);
}
