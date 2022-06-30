/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <youhnia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 07:58:36 by youhnia           #+#    #+#             */
/*   Updated: 2017/02/16 07:58:36 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_func_up(t_env *e, int x, int y)
{
	float tmp[2];

	tmp[0] = e->x1;
	tmp[1] = e->y2;
	e->x1 = tmp[0] + x * DIST_X * (e->zoom * ZOOM)	\
	/ IMAGE_X - DIST_X / 2 * e->zoom;
	e->x2 = tmp[0] + x * DIST_X * (e->zoom * ZOOM)	\
	/ IMAGE_X + DIST_X / 2 * e->zoom;
	e->y1 = tmp[1] - y * DIST_Y * (e->zoom * ZOOM)	\
	/ IMAGE_Y - DIST_Y / 2 * e->zoom;
	e->y2 = tmp[1] - y * DIST_Y * (e->zoom * ZOOM)	\
	/ IMAGE_Y + DIST_Y / 2 * e->zoom;
}

void	zoom_func_down(t_env *e, int x, int y)
{
	float tmp[2];

	tmp[0] = e->x1;
	tmp[1] = e->y2;
	e->x1 = tmp[0] + x * DIST_X * (e->zoom / ZOOM)	\
	/ IMAGE_X - DIST_X / 2 * e->zoom;
	e->x2 = tmp[0] + x * DIST_X * (e->zoom / ZOOM)	\
	/ IMAGE_X + DIST_X / 2 * e->zoom;
	e->y1 = tmp[1] - y * DIST_Y * (e->zoom / ZOOM)	\
	/ IMAGE_Y - DIST_Y / 2 * e->zoom;
	e->y2 = tmp[1] - y * DIST_Y * (e->zoom / ZOOM)	\
	/ IMAGE_Y + DIST_Y / 2 * e->zoom;
}

int		mouse_func(int mouse_code, int x, int y, t_env *e)
{
	if (mouse_code == 7)
	{
		clear_image(e);
		e->zoom /= ZOOM;
		zoom_func_up(e, x, y);
		if (ft_strcmp(e->fract_name, "mandelbrot") == 0)
			mandelbrot_fract(e);
		if (ft_strcmp(e->fract_name, "julia") == 0)
			julia_fract(e);
		if (ft_strcmp(e->fract_name, "tricorn") == 0)
			tricorn(e);
		if (ft_strcmp(e->fract_name, "burn") == 0)
			burning_ship(e);
		mlx_put_image_to_window(e->ptr, e->win, e->img, 0, 0);
		menu(e);
	}
	return (0);
}

int		mouse_func_two(int mouse_code, int x, int y, t_env *e)
{
	if (mouse_code == 6)
	{
		clear_image(e);
		e->zoom *= ZOOM;
		zoom_func_down(e, x, y);
		if (ft_strcmp(e->fract_name, "mandelbrot") == 0)
			mandelbrot_fract(e);
		if (ft_strcmp(e->fract_name, "julia") == 0)
			julia_fract(e);
		if (ft_strcmp(e->fract_name, "tricorn") == 0)
			tricorn(e);
		if (ft_strcmp(e->fract_name, "burn") == 0)
			burning_ship(e);
		mlx_put_image_to_window(e->ptr, e->win, e->img, 0, 0);
		menu(e);
	}
	else
		mouse_func(mouse_code, x, y, e);
	return (0);
}
