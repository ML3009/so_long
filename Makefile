# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 11:09:50 by mvautrot          #+#    #+#              #
#    Updated: 2022/12/29 10:03:13 by mvautrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long.a

CC=gcc

CFLAGS= -g3 -Wall -Wextra -Werror

SRC=src/map/ft_check_map.c\
	src/map/ft_check_map_utils.c\

OBJ=$(SRC:.c=.o)

MLX = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all : $(NAME)

$(NAME) : $(OBJ) mlx_linux/libmlx_Linux.a lib_dil/libft.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX)

%.o : %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

mlx_linux/libmlx_Linux.a:
	make -C mlx_linux

lib_dil/libft.a:
	make -C lib_dil

clean :
	make -C mlx_linux clean
	make -C lib_dil clean
	rm -rf *.o

fclean : clean
	make -C lib_dil clean
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY:	all clean fclean re
