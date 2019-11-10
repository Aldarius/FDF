# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lminta <lminta@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 20:58:32 by lminta            #+#    #+#              #
#    Updated: 2019/06/19 20:00:52 by lminta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../lib/libftmlx.a

INC = ../inc

FLAGS = -Wall -Werror -Wextra -c

OBJ = cam_koen.o ft_draw_line.o global_fill1.o global_fill2.o print_matrix.o \
round_fun.o init.o

all: $(NAME)

$(NAME): $(OBJ)
	make -C ../matrix
	ar rc $(NAME) $(OBJ) ../lib/libmatrix.a

$(OBJ): %.o: %.c
	gcc $(FLAGS) -I$(INC) $< -o $@

clean:
	make -C ../matrix clean
	rm -f $(OBJ)

fclean: clean
	make -C ../matrix fclean
	rm -f $(NAME)

re: fclean all
