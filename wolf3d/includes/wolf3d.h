/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <youhnia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 19:59:57 by youhnia           #+#    #+#             */
/*   Updated: 2017/03/06 19:59:57 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "libft.h"
# include "mlx.h"
# include <math.h>
# define WIDTH 640
# define HEIGHT 400
# define DIST_MAX 6400

# define PAS 20
# define AVANCER 65362
# define RECULER 65364
# define ROT_D 65363
# define ROT_G 65361
# define EXIT 65307

typedef struct		s_cam
{
	float			x;
	float			y;
	float			ang;
}					t_cam;

typedef struct		s_env
{
	void			*ptr;
	void			*win;
	void			*img;
	char			*data_img;
	t_cam			*c;
	char			**tab;
	char			**map;
	int				nb_column;
	int				nb_line;
	int				fd;
	char			*line;
	int				i;
	int				j;
	char			**tmp;
}					t_env;

void				tab(t_env *e);
void				ft_creat_tab(t_env *e);
void				init_env(t_env *e);
void				loop(t_env *e);
int					ft_collision(float *var, int card, t_env *e);
int					ft_mult(t_cam *c, float ang_r, char *type);
void				print(t_env *e, int card, float proj, int nb_rayon);
int					expose(t_env *e);
float				ft_cam_dist(t_cam *c, float *b);
void				eq(float ang_r, t_cam *c, char *type, float *var);
void				raycaster(t_env *e, int nb_rayon);

#endif
