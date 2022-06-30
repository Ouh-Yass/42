/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <youhnia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:50:12 by youhnia           #+#    #+#             */
/*   Updated: 2017/01/20 01:52:29 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_loop(char **buf, int *ret, char **save, int fd)
{
	char	*tmp;

	while (!ft_strchr(*buf, '\n'))
	{
		if ((*ret = read(fd, *buf, BUFF_SIZE)) == -1)
			return (-1);
		(*buf)[*ret] = 0;
		tmp = *save;
		*save = ft_strjoin(*save, *buf);
		free(tmp);
		if (*ret < BUFF_SIZE)
		{
			if (!(*ret))
				*buf = ft_strdup(*save);
			break ;
		}
	}
	return (0);
}

void		get_line(char *save, char *buf, int *ret, char **line)
{
	int		i;

	if (*ret && ft_strchr(buf, '\n'))
	{
		i = -1;
		while (save[++i] != '\n')
			;
		*line = ft_strsub(save, 0, i);
		i = -1;
		while (buf[++i] != '\n')
			;
		ft_memmove(buf, buf + (i + 1), *ret - i);
		if (*ret == BUFF_SIZE)
			buf[*ret - i] = 0;
		free(save);
	}
	else if (buf[0])
	{
		*line = ft_strdup(save);
		free(save);
		buf[0] = 0;
	}
}

t_gnl		*var_init(void)
{
	t_gnl	*var;

	var = NULL;
	var = (t_gnl *)ft_memalloc(sizeof(t_gnl));
	var->ret = 0;
	var->save = NULL;
	return (var);
}

int			get_next_line(int fd, char **line)
{
	static char	*buf[MAXFD] = {NULL};
	t_gnl		*var;

	var = var_init();
	if ((fd < 2 && fd != 0) || !line || fd >= MAXFD)
		return (-1);
	*line = NULL;
	if (!buf[fd])
	{
		if (!(buf[fd] = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (-1);
	}
	var->save = ft_strdup(buf[fd]);
	if ((ft_loop(&buf[fd], &var->ret, &var->save, fd)) == -1)
		return (-1);
	if (!var->ret)
		var->ret = ft_strlen(buf[fd]);
	if ((var->ret && ft_strchr(buf[fd], '\n')) || buf[fd][0])
	{
		get_line(var->save, buf[fd], &var->ret, line);
		return (1);
	}
	free(buf[fd]);
	buf[fd] = NULL;
	return (0);
}
