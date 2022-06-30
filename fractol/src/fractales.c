/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <youhnia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 06:46:50 by youhnia           #+#    #+#             */
/*   Updated: 2017/02/16 06:46:50 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fract_var(t_env *e)
{
	if (ft_strcmp(e->fract_name, "julia") != 0)
	{
		e->c_r = e->x1 + e->x * (e->x2 - e->x1) / IMAGE_X;
		e->c_i = e->y2 - e->y * (e->y2 - e->y1) / IMAGE_Y;
		e->z_r = 0;
		e->z_i = 0;
	}
}

void		burning_ship(t_env *e)
{
	e->x = -1;
	while (++e->x < IMAGE_X)
	{
		e->y = -1;
		while (++e->y < IMAGE_Y)
		{
			e->i = 0;
			fract_var(e);
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < IT_MAX)
			{
				e->tmp = fabs(e->z_r);
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->tmp * fabs(e->z_i) + e->c_i;
				e->i++;
			}
			if (e->i == IT_MAX)
				*((int *)e->data_img + e->y * IMAGE_X + e->x) = 0x000000;
			else
				*((int *)e->data_img + e->y * IMAGE_X + e->x) = 0x33FF99 * \
				fabs(cos(e->i));
		}
	}
}

void		tricorn(t_env *e)
{
	e->x = -1;
	while (++e->x < IMAGE_X)
	{
		e->y = -1;
		while (++e->y < IMAGE_Y)
		{
			e->i = 0;
			fract_var(e);
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < IT_MAX)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->tmp * -1 * e->z_i + e->c_i;
				e->i++;
			}
			if (e->i == IT_MAX)
				*((int *)e->data_img + e->y * IMAGE_X + e->x) = 0x000000;
			else
				*((int *)e->data_img + e->y * IMAGE_X + e->x) = 0xFFFF33\
				* fabs(cos(e->i));
		}
	}
}

void		julia_fract(t_env *e)
{
	e->x = -1;
	while (++e->x < IMAGE_X)
	{
		e->y = -1;
		while (++e->y < IMAGE_Y)
		{
			e->z_r = e->x1 + e->x * (e->x2 - e->x1) / IMAGE_X;
			e->z_i = e->y2 - e->y * (e->y2 - e->y1) / IMAGE_Y;
			e->i = 0;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < IT_MAX)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->tmp * e->z_i + e->c_i;
				e->i++;
			}
			if (e->i == IT_MAX)
				*((int *)e->data_img + e->y * IMAGE_X + e->x) = 0x000000;
			else
				*((int *)e->data_img + e->y * IMAGE_X + e->x) = 0xCC0033\
				* fabs(cos(e->i));
		}
	}
}

void		mandelbrot_fract(t_env *e)
{
	e->x = -1;
	while (++e->x < IMAGE_X)
	{
		e->y = -1;
		while (++e->y < IMAGE_Y)
		{
			e->i = 0;
			fract_var(e);
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < IT_MAX)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->tmp * e->z_i + e->c_i;
				e->i++;
			}
			if (e->i == IT_MAX)
				*((int *)e->data_img + e->y * IMAGE_X + e->x) = 0x000000;
			else
				*((int *)e->data_img + e->y * IMAGE_X + e->x) = 0x6600FF \
					* fabs(cos(e->i));
		}
	}
}
