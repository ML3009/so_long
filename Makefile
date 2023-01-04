# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 11:09:50 by mvautrot          #+#    #+#              #
#    Updated: 2023/01/03 16:49:24 by mvautrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long

CC=cc

CFLAGS= -Wall -Wextra -Werror -g3

PATH_SRC = src
SRC= $(PATH_SRC)/ft_check_map.c\
	$(PATH_SRC)/ft_check_map_utils.c\
	$(PATH_SRC)/ft_read_map.c\
	$(PATH_SRC)/ft_read_map_utils.c\
	$(PATH_SRC)/ft_moves_utils.c\
	$(PATH_SRC)/ft_moves.c\
	$(PATH_SRC)/ft_hook.c\
	$(PATH_SRC)/main.c

PATH_MLX = mlx_linux
MLX = $(PATH_MLX)/libmlx_Linux.a -I $(PATH_MLX) -L $(PATH_MLX) -lXext -lX11 -lm -lmlx

PATH_LIB = lib_dil
LIB = $(PATH_LIB)/libft.a

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ) $(MLX) $(LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) $(LIB)

# %.o : %.c
.c.o:
	$(CC) $(CFLAGS) -I /usr/include -c $< -o $@

$(MLX):
	make -C $(PATH_MLX)

$(LIB):
	make -C $(PATH_LIB)

clean:
	make -C $(PATH_MLX) clean
	make -C $(PATH_LIB) clean
	rm -f $(OBJ)


fclean: clean
	make -C $(PATH_LIB) fclean
	make -C $(PATH_MLX) clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
