/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <youhnia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 03:52:06 by youhnia           #+#    #+#             */
/*   Updated: 2017/02/16 03:52:06 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		init_tab(t_env *e, char *path)
{
	int		i;

	if ((e->fd = open(path, O_RDONLY)) == -1)
	{
		ft_putstr("error open fd");
		exit(0);
	}
	while ((get_next_line(e->fd, &e->line) == 1))
	{
		e->nb_line[0]++;
		i = -1;
		e->space = 1;
		while (e->line[++i])
		{
			if (e->line[i] == ' ')
			{
				while (e->line[i] == 32)
					i++;
				e->space++;
			}
		}
		if (e->space > (int)e->len)
			e->len = e->space;
	}
	close(e->fd);
}

char			**creat_tab(t_env *e, char *path)
{
	char	**tab;
	int		i;

	tab = NULL;
	init_tab(e, path);
	if (!(tab = (char **)ft_memalloc(sizeof(char*) * (e->nb_line[0] + 1))))
		exit(0);
	e->fd = open(path, O_RDONLY);
	e->nb_line[1] = 0;
	while ((get_next_line(e->fd, &e->line)) == 1)
	{
		tab[e->nb_line[1]] = ft_strdup(e->line);
		e->nb_line[1]++;
	}
	close(e->fd);
	if (!(e->map = (int **)ft_memalloc(sizeof(int *) * e->nb_line[0])))
		exit(0);
	i = -1;
	while (++i < e->nb_line[0])
	{
		if (!(e->map[i] = (int *)ft_memalloc(sizeof(int) * e->len)))
			exit(0);
	}
	return (tab);
}

int				is_valid_map(char **map)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if ((map[i][j] < 48 && map[i][j] != 32 && map[i][j] != 44) ||\
				(map[i][j] > 57 && (map[i][j] < 'A' || map[i][j] > 'F')\
				&& (map[i][j] < 'a' || map[i][j] > 'f') && map[i][j] != 'x'))
			{
				ft_putstr("not a valid file\n");
				return (-1);
			}
		}
	}
	if (!map[0])
	{
		ft_putstr("not a valid file\n");
		return (-1);
	}
	return (0);
}

void			get_z(t_env *e, char **tab)
{
	while (++e->it < e->nb_line[0])
	{
		e->jt = -1;
		e->k = 0;
		while (tab[e->it][++e->jt])
		{
			while (tab[e->it][e->jt] == 32 && tab[e->it][e->jt])
				e->jt++;
			e->map[e->it][e->k] = ft_atoi(tab[e->it] + e->jt);
			e->k++;
			if (e->k == (int)e->len)
				break ;
			while (tab[e->it][e->jt] != 32 && tab[e->it][e->jt])
				e->jt++;
			e->jt--;
		}
		if (e->k != (int)e->len)
		{
			while (e->k != (int)e->len)
			{
				e->map[e->it][e->k] = 0;
				e->k++;
			}
		}
	}
}
