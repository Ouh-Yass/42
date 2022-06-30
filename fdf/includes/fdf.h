/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <youhnia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 22:23:54 by youhnia           #+#    #+#             */
/*   Updated: 2017/02/03 22:23:54 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include "libft.h"
# include <stdio.h>
# define LENGHT 1200
# define WIDHT 1200

typedef struct	s_fxy
{
	float		x;
	float		y;
}				t_fxy;

typedef struct	s_env
{
	void	*ptr;
	void	*win;
	int		nb_line[2];
	size_t	len;
	int		**map;
	t_fxy	**tabb;
	int		x_offset;
	int		y_offset;
	int		zoom;
	char	*line;
	int		fd;
	int		space;
	int		it;
	int		jt;
	int		k;
	int		color;
}				t_env;

void			get_z(t_env *e, char **tab);
void			draw(t_env *e);
char			**creat_tab(t_env *e, char *path);
int				is_valid_map(char **map);

#endif
