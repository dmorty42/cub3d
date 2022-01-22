# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmorty <dmorty@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/20 02:33:40 by dmorty            #+#    #+#              #
#    Updated: 2022/01/22 18:34:00 by dmorty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d
CC		= gcc
FLAGS	= -Wall -Werror -Wextra
CFLAGS	= $(FLAGS) -I. -Imlx -Ilibft
SRC		=	./srcs/main.c
OBJ		= $(SRC:%.c=%.o)
INC		= ./includes/cub3d.h

.PHONY: all re clean fclean libft mlx

.o: .c
	$(CC) $(CFLAGS) -Imlx $< -o $@

all: mlx libft $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CC) $(OBJ) -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

mlx:
	make -C mlx/

libft:
	make -C libft/

clean:
	make -C mlx/ clean
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	rm -f mlx/libmlx.a
	rm -f libft/libft.a
	rm -f $(NAME)

re: fclean all
