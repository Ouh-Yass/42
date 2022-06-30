/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <youhnia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:12:27 by youhnia           #+#    #+#             */
/*   Updated: 2017/03/06 18:12:27 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		free_split(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void		ft_parsing(t_env *e)
{
	int			i;

	tab(e);
	i = -1;
	e->nb_line = 0;
	e->nb_column = 0;
	while (e->tab[++i])
	{
		e->nb_line++;
		e->tmp = ft_strsplit(e->tab[i], ' ');
		e->i = -1;
		while (e->tmp[++e->i])
			;
		if (e->i > e->nb_column)
			e->nb_column = e->i;
		free_split(e->tmp);
	}
}

void		ft_creat_tab(t_env *e)
{
	int		i;

	ft_parsing(e);
	if ((e->map = (char **)ft_memalloc(sizeof(char *) * e->nb_line)) == NULL)
		exit(0);
	e->i = -1;
	while (++e->i < e->nb_line)
	{
		if ((e->map[e->i] = (char *)ft_memalloc(sizeof(char) * e->nb_column)) \
			== NULL)
			exit(0);
	}
	e->i = 0;
	i = -1;
	while (e->tab[++i])
	{
		e->tmp = ft_strsplit(e->tab[i], ' ');
		e->j = -1;
		while (e->tmp[++e->j])
			e->map[e->i][e->j] = (char)ft_atoi(e->tmp[e->j]);
		e->i++;
		free_split(e->tmp);
	}
	free(e->tab);
	e->tab = NULL;
}
