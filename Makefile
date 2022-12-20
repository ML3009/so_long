# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 11:09:50 by mvautrot          #+#    #+#              #
#    Updated: 2022/12/20 14:59:25 by mvautrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=mlx.a
CC=cc
CFLAGS=-Wall -Wextra -Werror

#SRC=

OBJ=$(SRC:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lXext -lX11 -lm -lz -o $(NAME)

all : $(NAME)

clean : 
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY:	all clean fclean re
