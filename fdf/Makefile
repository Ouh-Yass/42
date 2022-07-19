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
FLAGS = -Wall -Werror -Wextra
NAME = fdf
SRC = src/parsing.c\
	src/pixels_line.c\
	main.c

OBJ = $(SRC:.c=.o)
INCLUDES = includes/
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


