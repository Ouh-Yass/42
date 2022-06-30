/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <youhnia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:01:31 by youhnia           #+#    #+#             */
/*   Updated: 2017/03/06 18:01:31 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init_env(t_env *e)
{
	int		tmp[3];

	e->ptr = mlx_init();
	e->img = mlx_new_image(e->ptr, WIDTH, HEIGHT);
	e->data_img = mlx_get_data_addr(e->img, tmp, tmp + 1, tmp + 2);
	e->win = mlx_new_window(e->ptr, WIDTH, HEIGHT, "wolf3d");
	e->c = (t_cam *)ft_memalloc(sizeof(t_cam));
	e->c->ang = 0;
	e->c->x = 96;
	e->c->y = 160;
}
