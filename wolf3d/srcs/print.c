/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <youhnia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:04:27 by youhnia           #+#    #+#             */
/*   Updated: 2017/03/06 18:04:27 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		print(t_env *e, int card, float proj, int nb_rayon)
{
	int		color;
	int		nb_pix;
	int		i;
	int		start;

	nb_pix = proj * HEIGHT;
	start = (HEIGHT - nb_pix) / 2;
	if (card == 0)
		color = 0x0000FF;
	if (card == 1)
		color = 0x00FF00;
	if (card == 2)
		color = 0xFF0000;
	if (card == 3)
		color = 0xFF00FF;
	i = 0;
	while (++i < nb_pix)
		*((int *)e->data_img + (start + i) * WIDTH + nb_rayon) = color;
}
