# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/23 12:58:10 by mberedda          #+#    #+#              #
#    Updated: 2016/12/09 17:32:41 by mberedda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mberedda.filler

SRC_PATH = src/

SRC = 	main.c\
		./src/read_map.c\
		./src/get_piece.c\
		./src/piece_coor.c\
		./src/alog_place_to_play.c
		
OBJ = ./src/$(SRC:.c=.o)

INCLUDE = include/filler.h

LIBFT = libft/libft.h

LIB = lib/libftprintf.a

CFLAGS = -Wall -Wextra -Werror -I .

CC = gcc

.PHONY: all lib clean fclean re
.SILENT:

all: $(NAME)

$(NAME): lib $(OBJ)
	@$(CC) -o $(NAME) $(LIB) $(OBJ) -L libft -lft

lib:
	@make -C libft

clean:
	@make clean -C libft
	@/bin/rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all
