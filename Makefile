# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 11:09:50 by mvautrot          #+#    #+#              #
#    Updated: 2023/01/18 15:39:54 by mvautrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long

NAME_BONUS=so_long_bonus

CC=@cc

CFLAGS= -Wall -Wextra -Werror -g3

PATH_SRC = src
PATH_SRC_BONUS = src_bonus
SRC= $(PATH_SRC)/ft_check_map_utils.c\
	 $(PATH_SRC)/ft_check_map.c\
	 $(PATH_SRC)/ft_check_path.c\
	 $(PATH_SRC)/ft_gestion_error.c\
	 $(PATH_SRC)/ft_gestion_init.c\
	 $(PATH_SRC)/ft_hook.c\
	 $(PATH_SRC)/ft_moves.c\
	 $(PATH_SRC)/ft_put_map.c\
	 $(PATH_SRC)/ft_read_map_utils.c\
	 $(PATH_SRC)/ft_read_map.c\

SRC_BONUS = $(PATH_SRC_BONUS)/ft_check_map_utils_bonus.c\
			$(PATH_SRC_BONUS)/ft_check_map_bonus.c\
			$(PATH_SRC_BONUS)/ft_check_path_bonus.c\
			$(PATH_SRC_BONUS)/ft_gestion_error_bonus.c\
			$(PATH_SRC_BONUS)/ft_gestion_init_bonus.c\
			$(PATH_SRC_BONUS)/ft_hook_bonus.c\
			$(PATH_SRC_BONUS)/ft_moves_bonus.c\
			$(PATH_SRC_BONUS)/ft_put_map_bonus.c\
			$(PATH_SRC_BONUS)/ft_read_map_utils_bonus.c\
			$(PATH_SRC_BONUS)/ft_read_map_bonus.c\

PATH_MLX = mlx_linux
MLX = $(PATH_MLX)/libmlx_Linux.a -L $(PATH_MLX) -lXext -lX11 -lm -lmlx

PATH_LIB = lib_dil
LIB = $(PATH_LIB)/libft.a

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(MLX) $(LIB) $(NAME) $(NAME_BONUS)

bonus: $(MLX) $(LIB) $(NAME_BONUS)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) src/main.c -o $(NAME) $(OBJ) $(MLX) $(LIB)
	@echo "\nCompilation OK\n"

$(NAME_BONUS) : $(OBJ_BONUS)
	$(CC) $(CFLAGS) src_bonus/main_bonus.c -o $(NAME_BONUS) $(OBJ_BONUS) $(MLX) $(LIB)
	@echo "\nCompilation Bonus OK\n"

.c.o:
	$(CC) $(CFLAGS)  -c $< -o $@ -I $(PATH_MLX)

$(MLX):
	@make -s -C $(PATH_MLX)

$(LIB):
	@make -s -C $(PATH_LIB)

clean:
	make -C $(PATH_MLX) clean
	make -C $(PATH_LIB) clean
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)

fclean: clean
	make -C $(PATH_LIB) fclean
	make -C $(PATH_MLX) clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

.PHONY:	all clean fclean re
