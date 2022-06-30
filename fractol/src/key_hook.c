/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <youhnia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 08:39:47 by youhnia           #+#    #+#             */
/*   Updated: 2017/02/16 08:39:47 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_func(int keycode, t_env *e)
{
	float	tmp;

	if (keycode == 53)
		exit(0);
	if (keycode == 123)
	{
		clear_image(e);
		tmp = e->x2 - e->x1;
		e->x1 += tmp / e->offset;
		e->x2 += tmp / e->offset;
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
		julia_key(keycode, e);
	return (0);
}

int		key_func_two(int keycode, t_env *e)
{
	float		tmp;

	if (keycode == 124)
	{
		clear_image(e);
		tmp = e->x2 - e->x1;
		e->x1 -= tmp / e->offset;
		e->x2 -= tmp / e->offset;
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
		key_func(keycode, e);
	return (0);
}

int		key_func_three(int keycode, t_env *e)
{
	float	tmp;

	if (keycode == 125)
	{
		clear_image(e);
		tmp = e->x2 - e->x1;
		e->y1 += tmp / e->offset;
		e->y2 += tmp / e->offset;
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
		key_func_two(keycode, e);
	return (0);
}

int		key_func_four(int keycode, t_env *e)
{
	float		tmp;

	if (keycode == 126)
	{
		clear_image(e);
		tmp = e->x2 - e->x1;
		e->y1 -= tmp / e->offset;
		e->y2 -= tmp / e->offset;
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
		key_func_three(keycode, e);
	return (0);
}

int		key_func_five(int keycode, t_env *e)
{
	if (keycode == 49)
	{
		clear_image(e);
		init_env(e);
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
		key_func_four(keycode, e);
	return (0);
}
