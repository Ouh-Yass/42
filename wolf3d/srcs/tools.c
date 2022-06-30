/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <youhnia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:08:52 by youhnia           #+#    #+#             */
/*   Updated: 2017/03/06 18:08:52 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

float		ft_cam_dist(t_cam *c, float *b)
{
	return (sqrt(pow(b[0] - c->x, 2) + pow(b[1] - c->y, 2)));
}

int			ft_mult(t_cam *c, float ang_r, char *type)
{
	if (ft_strcmp(type, "v") == 0 && cos(ang_r) > 0)
		return (((int)c->x / 64 + 1) * 64);
	if (ft_strcmp(type, "v") == 0 && cos(ang_r) < 0)
		return (((int)c->x / 64) * 64);
	if (ft_strcmp(type, "h") == 0 && sin(ang_r) > 0)
		return (((int)c->y / 64 + 1) * 64);
	if (ft_strcmp(type, "h") == 0 && sin(ang_r) < 0)
		return (((int)c->y / 64) * 64);
	return (-42);
}

void		eq(float ang_r, t_cam *c, char *type, float *var)
{
	if (ft_strcmp(type, "v") == 0 && cos(ang_r) == 0)
		var[1] = -42;
	else if (ft_strcmp(type, "v") == 0)
		var[1] = tan(ang_r) * var[0] + c->y - tan(ang_r) * c->x;
	else if (ft_strcmp(type, "h") == 0 && sin(ang_r) == 0)
		var[0] = -42;
	else if (ft_strcmp(type, "h") == 0 && cos(ang_r) == 0)
		var[0] = c->x;
	else if (ft_strcmp(type, "h") == 0)
		var[0] = (var[1] - c->y + tan(ang_r) * c->x) / tan(ang_r);
}

int			ft_collision(float *var, int card, t_env *e)
{
	if (var[0] < 64 || var[0] > (e->nb_column - 1) * 64
		|| var[1] < 64 || var[1] > (e->nb_line - 1) * 64)
		return (-42);
	else if (card == 2)
		return (e->map[(int)var[1] / 64][(int)var[0] / 64]);
	else if (card == -2)
		return (e->map[(int)var[1] / 64][(int)var[0] / 64 - 1]);
	else if (card == 1)
		return (e->map[(int)var[1] / 64][(int)var[0] / 64]);
	else if (card == -1)
		return (e->map[(int)var[1] / 64 - 1][(int)var[0] / 64]);
	return (-42);
}
