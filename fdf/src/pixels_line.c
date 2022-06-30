/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <youhnia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 20:43:19 by youhnia           #+#    #+#             */
/*   Updated: 2017/02/04 02:33:36 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		creat_line(t_env *e, t_fxy hp, t_fxy mp, int color)
{
	int			i;
	t_fxy		start;

	i = 0;
	if (fabs(mp.x - hp.x) > fabs(mp.y - hp.y))
	{
		start = mp.x < hp.x ? mp : hp;
		while (i < fabs(mp.x - hp.x))
		{
			mlx_pixel_put(e->ptr, e->win, (start.x + i), (mp.y - hp.y) / \
			(mp.x - hp.x) * ((start.x + i) - start.x) + start.y, color);
			i++;
		}
	}
	else
	{
		start = mp.y < hp.y ? mp : hp;
		while (i < fabs(mp.y - hp.y))
		{
			mlx_pixel_put(e->ptr, e->win, (mp.x - hp.x) / (mp.y - hp.y) \
			* ((start.y + i) - start.y) + start.x, start.y + i, color);
			i++;
		}
	}
}

static void		convert(t_env *e)
{
	int		x;
	int		y;

	e->tabb = NULL;
	y = -1;
	if (!(e->tabb = (t_fxy **)ft_memalloc(sizeof(t_fxy *) * e->nb_line[0])))
		exit(0);
	while (++y < e->nb_line[0])
	{
		x = -1;
		if (!(e->tabb[y] = (t_fxy *)ft_memalloc(sizeof(t_fxy) * e->len)))
			exit(0);
		while (++x < (int)e->len)
		{
			e->tabb[y][x].x = (x + y) * e->zoom + e->x_offset;
			e->tabb[y][x].y = (y + cos(2) * (x + y) - e->map[y][x])\
			* e->zoom + e->y_offset;
		}
	}
}

void			draw(t_env *e)
{
	int		x;
	int		y;

	convert(e);
	y = -1;
	while (++y < e->nb_line[0])
	{
		x = -1;
		while (++x < (int)e->len)
		{
			if (x < (int)e->len - 1)
				creat_line(e, e->tabb[y][x + 1], e->tabb[y][x], e->color);
			if (y < e->nb_line[0] - 1)
				creat_line(e, e->tabb[y + 1][x], e->tabb[y][x], e->color);
		}
	}
	mlx_string_put(e->ptr, e->win, 10, 20, 0xFFFFFF, "ESC    = Exit");
	mlx_string_put(e->ptr, e->win, 10, 40, 0xFFFFFF, "Arrow  = Offset");
	mlx_string_put(e->ptr, e->win, 10, 60, 0xFFFFFF, "Space  = Reset");
	mlx_string_put(e->ptr, e->win, 10, 80, 0xFFFFFF, "1 - 2  = Zoom");
	mlx_string_put(e->ptr, e->win, 10, 100, 0xFFFFFF, "4 - 5  = Red - Blue");
}
