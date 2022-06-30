/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhnia <youhnia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:05:10 by youhnia           #+#    #+#             */
/*   Updated: 2016/11/15 18:24:37 by youhnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 42
# define MAXFD 2048
# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>

int get_next_line(const int fd, char **line);

#endif
