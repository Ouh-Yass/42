/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <youhnia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 08:47:17 by youhnia           #+#    #+#             */
/*   Updated: 2017/02/16 08:47:17 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h>
# include <math.h>
# define IMAGE_X 800
# define IMAGE_Y 800
# define DIST_X 2.7
# define DIST_Y 2.4
# define ZOOM 1.5
# define IT_MAX 250

typedef struct		s_env
{
	void	*ptr;
	void	*win;
	void	*img;
	char	*data_img;
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	int		offset;
	float	zoom;
	float	c_r;
	float	c_i;
	float	z_r;
	float	z_i;
	char	*fract_name;
	int		x;
	int		y;
	int		i;
	float	tmp;
	int		prev[2];
	int		ver_prev[2];
	int		ver;
}					t_env;

void				mandelbrot_fract(t_env *e);
void				julia_fract(t_env *e);
void				tricorn(t_env *e);
void				burning_ship(t_env *e);
void				init_env(t_env *e);
void				clear_image(t_env *e);
int					mouse_func_two(int mouse_code, int x, int y, t_env *e);
int					key_func_five(int keycode, t_env *e);
void				menu(t_env *e);
int					julia_cursor(t_env *e);
int					recup_pix(int x, int y, t_env *e);
int					julia_key(int keycode, t_env *e);

#endif
