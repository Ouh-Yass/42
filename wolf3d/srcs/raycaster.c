/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <youhnia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:06:47 by youhnia           #+#    #+#             */
/*   Updated: 2017/03/06 18:06:47 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

float		hori_dist(t_env *e, float ang_r)
{
	float	ret;
	float	var[2];
	int		sens;

	ret = -42;
	sens = sin(ang_r) > 0 ? 1 : -1;
	var[1] = ft_mult(e->c, ang_r, "h");
	while (ret < DIST_MAX)
	{
		eq(ang_r, e->c, "h", var);
		ret = ft_cam_dist(e->c, var);
		if (ft_collision(var, sens, e) == 1)
			return (ret);
		var[1] += sens * 64;
	}
	return (ret);
}

float		vert_dist(t_env *e, float ang_r)
{
	float	ret;
	float	var[2];
	int		sens;

	ret = -42;
	sens = cos(ang_r) > 0 ? 2 : -2;
	var[0] = ft_mult(e->c, ang_r, "v");
	while (ret < DIST_MAX)
	{
		eq(ang_r, e->c, "v", var);
		ret = ft_cam_dist(e->c, var);
		if (ft_collision(var, sens, e) == 1)
			return (ret);
		var[0] += sens / 2 * 64;
	}
	return (ret);
}

void		raycaster(t_env *e, int nb_rayon)
{
	int		card;
	float	ang_r;
	float	dist;
	float	tmp[2];
	float	proj;

	ang_r = e->c->ang - M_PI / 6 + nb_rayon * M_PI / 3 / 640;
	tmp[0] = hori_dist(e, ang_r);
	tmp[1] = vert_dist(e, ang_r);
	dist = (tmp[0] < tmp[1]) ? tmp[0] : tmp[1];
	if (dist < DIST_MAX)
	{
		card = (dist == tmp[0]) ? 0 : 1;
		if (card == 0)
			card = (sin(ang_r) > 0) ? 1 : 3;
		else
			card = (cos(ang_r) > 0) ? 0 : 2;
		proj = 554 * 64 / dist;
		proj = (proj > HEIGHT) ? 1 : proj / HEIGHT;
		print(e, card, proj, nb_rayon);
	}
}
