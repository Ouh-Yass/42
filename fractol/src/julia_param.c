/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <youhnia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 17:58:21 by youhnia           #+#    #+#             */
/*   Updated: 2017/02/22 17:58:21 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julia_key(int keycode, t_env *e)
{
	if (keycode == 83)
	{
		e->ver = e->ver == 0 ? 1 : 0;
		if (e->ver)
		{
			e->ver_prev[0] = e->prev[0];
			e->ver_prev[1] = e->prev[1];
		}
	}
	return (0);
}

int		recup_pix(int x, int y, t_env *e)
{
	e->prev[0] = x;
	e->prev[1] = y;
	return (0);
}

int		julia_cursor(t_env *e)
{
	if (e->ver == 0)
	{
		e->c_r = e->x1 + e->prev[0] * (e->x2 - e->x1) / IMAGE_X;
		e->c_i = e->y1 + e->prev[1] * (e->y2 - e->y1) / IMAGE_Y;
	}
	else
	{
		e->c_r = e->x1 + e->ver_prev[0] * (e->x2 - e->x1) / IMAGE_X;
		e->c_i = e->y1 + e->ver_prev[1] * (e->y2 - e->y1) / IMAGE_Y;
	}
	julia_fract(e);
	mlx_put_image_to_window(e->ptr, e->win, e->img, 0, 0);
	menu(e);
	return (0);
}
