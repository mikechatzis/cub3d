# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 20:17:37 by ekraujin          #+#    #+#              #
#    Updated: 2022/03/21 18:04:18 by ekraujin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = main.c error.c make_map.c check_map.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	make -C mlx/
	$(CC) $(OBJ) mlx/libmlx.a libft/libft.a -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C mlx/
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re