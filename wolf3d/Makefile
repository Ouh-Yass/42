#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youhnia <youhnia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/20 01:39:24 by youhnia           #+#    #+#              #
#    Updated: 2017/01/20 04:43:38 by youhnia          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
FLAGS = -Wall -Werror -Wextra -ggdb
NAME = wolf3d
SRC = srcs/main.c\
	srcs/init_env.c\
	srcs/parsing.c\
	srcs/loop.c\
	srcs/tools.c\
	srcs/raycaster.c\
	srcs/print.c\
	srcs/map.c\

OBJ = $(SRC:.c=.o)
INCLUDES = includes/
#LIB = -L libft/ -lft -L ./usr/lib/ -lmlx -lft -L /usr/X11/lib -lX11 -lXext -lm -fPIC
LIB = -L libft/ -lft -L ./ -lmlx -L /usr/lib/x86_64-linux-gnu/ -lX11 -lXext -lm 

all: $(NAME)

$(NAME): ./libft/libft.a $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -I $(INCLUDES) $(LIB) $(FLAGS)

./libft/libft.a :
	make -C libft/ fclean && make -C libft/ && make -C libft/ clean

%.o: %.c
	$(CC) -o $@ -c $< -I $(INCLUDES) -I ./ $(FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean $(NAME)


