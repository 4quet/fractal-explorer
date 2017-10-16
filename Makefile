# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/03 18:23:54 by lfourque          #+#    #+#              #
#    Updated: 2015/03/03 19:54:35 by lfourque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC = main.c\
	  fractal_type.c\
	  hooks.c\
	  init_param.c\
	  coords.c\
	  modulus.c\
	  draw.c\
	  colorset.c\
	  move_fractal.c\
	  zoom.c
DIR_SRC = $(addprefix src/, $(SRC))
OBJ = $(SRC:.c=.o)
FLAG = -Wall -Werror -Wextra
LIB = -framework OpenGL -framework Appkit -L /usr/local/lib -lmlx

.PHONY : libft.a clean flcean re

all: $(NAME)

$(NAME): $(DIR_SRC) includes/fractol.h
	make -C libft/ re
	gcc $(FLAG) -I includes/ -c $(DIR_SRC)
	gcc -o $(NAME) $(OBJ) libft/libft.a -I includes/ $(LIB)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
