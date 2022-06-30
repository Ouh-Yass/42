/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <youhnia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:04:57 by youhnia           #+#    #+#             */
/*   Updated: 2017/03/06 18:04:57 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			key_func(int keycode, t_env *e)
{
	if (keycode == EXIT)
		exit(0);
	else if (keycode == AVANCER)
	{
		e->c->x += PAS * cos(e->c->ang);
		e->c->y += PAS * sin(e->c->ang);
	}
	else if (keycode == RECULER)
	{
		e->c->x -= PAS * cos(e->c->ang);
		e->c->y -= PAS * sin(e->c->ang);
	}
	else if (keycode == ROT_D)
		e->c->ang += M_PI / 8;
	else if (keycode == ROT_G)
		e->c->ang -= M_PI / 8;
	expose(e);
	return (0);
}

int			ft_exit_cross(void)
{
	exit(0);
}

void		clear_img(t_env *e)
{
	int	i;

	i = -1;
	while (++i < WIDTH * HEIGHT)
		*((int *)e->data_img + i) = 0;
}

int			expose(t_env *e)
{
	int		i;

	clear_img(e);
	i = -1;
	while (++i < 640)
		raycaster(e, i);
	mlx_put_image_to_window(e->ptr, e->win, e->img, 0, 0);
	return (0);
}

void		loop(t_env *e)
{
	mlx_key_hook(e->win, key_func, e);
	mlx_hook(e->win, 17, 1L << 17, ft_exit_cross, e);
	mlx_expose_hook(e->win, expose, e);
	mlx_loop(e->ptr);
}
