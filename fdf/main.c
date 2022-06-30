/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <youhnia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 03:49:41 by youhnia           #+#    #+#             */
/*   Updated: 2017/02/16 03:49:41 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int		key_func_last(int keycode, t_env *e)
{
	if (keycode == 49)
	{
		mlx_clear_window(e->ptr, e->win);
		e->zoom = 3;
		e->y_offset = LENGHT / 2;
		e->x_offset = WIDHT / 3;
		e->color = 0xFFFFFF;
		draw(e);
	}
	if (keycode == 87)
	{
		mlx_clear_window(e->ptr, e->win);
		e->color = 0x1825AE;
		draw(e);
	}
	if (keycode == 86)
	{
		mlx_clear_window(e->ptr, e->win);
		e->color = 0xC81001;
		draw(e);
	}
	return (0);
}

static int		key_func_two(int keycode, t_env *e)
{
	if (keycode == 83)
	{
		mlx_clear_window(e->ptr, e->win);
		e->zoom++;
		draw(e);
	}
	if (keycode == 84)
	{
		mlx_clear_window(e->ptr, e->win);
		e->zoom--;
		if (e->zoom == 0)
			e->zoom = 1;
		draw(e);
	}
	if (keycode == 126)
	{
		mlx_clear_window(e->ptr, e->win);
		e->y_offset = e->y_offset - 50;
		draw(e);
	}
	else
		key_func_last(keycode, e);
	return (0);
}

static int		key_func_one(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
	{
		mlx_clear_window(e->ptr, e->win);
		e->x_offset = e->x_offset - 50;
		draw(e);
	}
	if (keycode == 124)
	{
		mlx_clear_window(e->ptr, e->win);
		e->x_offset = e->x_offset + 50;
		draw(e);
	}
	if (keycode == 125)
	{
		mlx_clear_window(e->ptr, e->win);
		e->y_offset = e->y_offset + 50;
		draw(e);
	}
	else
		key_func_two(keycode, e);
	return (0);
}

static t_env	*init_env(void)
{
	t_env	*e;

	e = NULL;
	if (!(e = (t_env *)ft_memalloc(sizeof(t_env))))
		exit(0);
	e->zoom = 3;
	e->y_offset = LENGHT / 2;
	e->x_offset = WIDHT / 3;
	e->map = NULL;
	e->nb_line[0] = 0;
	e->nb_line[1] = -1;
	e->len = 0;
	e->color = 0xFFFFFF;
	e->line = NULL;
	e->it = -1;
	return (e);
}

int				main(int argc, char *argv[])
{
	t_env	*e;
	char	**tab;

	tab = NULL;
	if (argc != 2)
	{
		ft_putstr("usage : ./fdf <file_name>");
		return (1);
	}
	e = init_env();
	tab = creat_tab(e, argv[1]);
	if ((is_valid_map(tab)) == -1)
		exit(0);
	get_z(e, tab);
	e->ptr = mlx_init();
	e->win = mlx_new_window(e->ptr, LENGHT, WIDHT, "fdf");
	draw(e);
	mlx_key_hook(e->win, key_func_one, e);
	mlx_loop(e->ptr);
	return (0);
}
