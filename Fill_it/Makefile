# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lminta <lminta@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 20:58:32 by lminta            #+#    #+#              #
#    Updated: 2019/06/19 20:06:08 by lminta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../lib/libfl.a

INC = ../inc

FLAGS = -Wall -Werror -Wextra -c

OBJ = map.o \
move.o \
read.o \
control.o

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ) ../lib/libft.a

$(OBJ): %.o: %.c
	gcc $(FLAGS) -I$(INC) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
