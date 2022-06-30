/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <youhnia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 08:16:04 by youhnia           #+#    #+#             */
/*   Updated: 2017/02/16 08:16:04 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	menu(t_env *e)
{
	mlx_string_put(e->ptr, e->win, 10, 20, 0xFFFFFF, "ESC    = Exit");
	mlx_string_put(e->ptr, e->win, 10, 40, 0xFFFFFF, "Arrow  = Offset");
	mlx_string_put(e->ptr, e->win, 10, 60, 0xFFFFFF, "Scroll = Zoom");
	mlx_string_put(e->ptr, e->win, 10, 80, 0xFFFFFF, "Space  = Reset");
	mlx_string_put(e->ptr, e->win, 10, 100, 0xFFFFFF, "1      = Lock/Un\
	lock Julia");
}

void	clear_image(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	while (++i < IMAGE_Y)
	{
		j = -1;
		while (++j < IMAGE_X)
			*((int *)e->data_img + i * IMAGE_X + j) = 0;
	}
}

int		fract_choice(t_env *e)
{
	if (ft_strcmp(e->fract_name, "mandelbrot") == 0)
	{
		mandelbrot_fract(e);
		return (1);
	}
	else if (ft_strcmp(e->fract_name, "tricorn") == 0)
	{
		tricorn(e);
		return (1);
	}
	else if (ft_strcmp(e->fract_name, "julia") == 0)
		return (1);
	else if (ft_strcmp(e->fract_name, "burn") == 0)
	{
		burning_ship(e);
		return (1);
	}
	else
	{
		ft_putstr("error arg\n");
		return (0);
	}
}

void	init_env(t_env *e)
{
	int tmp[3];

	e->zoom = 1;
	e->prev[0] = IMAGE_X / 2;
	e->prev[1] = IMAGE_Y / 2;
	e->offset = 5;
	e->x1 = -2.1;
	e->x2 = 0.6;
	e->y1 = -1.2;
	e->y2 = 1.2;
	e->ptr = mlx_init();
	e->img = mlx_new_image(e->ptr, 800, 800);
	e->data_img = mlx_get_data_addr(e->img, tmp, tmp + 1, tmp + 2);
	e->ver = 0;
}

int		main(int argc, char *argv[])
{
	t_env *e;

	if (argc != 2)
	{
		ft_putstr("usage : ./fractol mandelbrot, julia, tricorn or burn");
		return (0);
	}
	e = (t_env *)ft_memalloc(sizeof(t_env));
	init_env(e);
	e->fract_name = ft_strdup(argv[1]);
	if (fract_choice(e) == 0)
		return (0);
	e->win = mlx_new_window(e->ptr, 800, 800, e->fract_name);
	mlx_put_image_to_window(e->ptr, e->win, e->img, 0, 0);
	menu(e);
	mlx_expose_hook(e->win, fract_choice, e);
	mlx_key_hook(e->win, key_func_five, e);
	mlx_mouse_hook(e->win, mouse_func_two, e);
	if (ft_strcmp(e->fract_name, "julia") == 0)
	{
		mlx_hook(e->win, 6, 1L << 6, recup_pix, e);
		mlx_loop_hook(e->ptr, julia_cursor, e);
	}
	mlx_loop(e->ptr);
	return (0);
}
