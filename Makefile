# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lminta <lminta@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 20:58:32 by lminta            #+#    #+#              #
#    Updated: 2019/11/10 17:38:12 by lminta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

INC = inc

LIBS = lib

FLAGS = -Wall -Werror -Wextra -c

FLAGS2 = -lft -lmatrix -lftmlx -lftgnl -lfl

OBJ = src/color_change.o src/fdf.o src/graf_print.o src/map_reader1.o src/map_reader2.o src/mods.o \
src/print_text.o src/fill_my_fdf.o src/fill_mod.o src/cam_fun.o

.PHONY: clean fclean re

all: $(LIBS) $(NAME)

$(NAME): $(OBJ)
	make -C mlx_graph
	make -C Get_Next_Line
	make -C Fill_it
	make -C minilibx_macos
	gcc $(OBJ) -L $(LIBS) $(FLAGS2) -I minilibx_macos -L minilibx_macos -lmlx -framework OpenGL -framework Appkit -o $(NAME)

$(LIBS):
	mkdir lib

$(OBJ): %.o: %.c
	gcc $(FLAGS) -I$(INC) $< -o $@

clean:
	make -C mlx_graph clean
	make -C Get_Next_Line clean
	make -C Fill_it clean
	make -C minilibx_macos clean
	rm -f $(OBJ)

fclean: clean
	make -C mlx_graph fclean
	make -C Fill_it fclean
	rm -f $(NAME)

re: fclean all
