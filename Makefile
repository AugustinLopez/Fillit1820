# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aulopez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 13:11:21 by aulopez           #+#    #+#              #
#    Updated: 2018/12/07 11:02:05 by aulopez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=Fillit1820

TARGETS=Fillit1820

PATH_SRC=./libft/
PATH_LIB=./libft
PATH_HLB=./libft/includes

LIBFT=$(PATH_LIB)/libft.a
SRC=$(TARGETS:%=%.c)
OBJ=$(SRC:%.c=%.o)

CC=gcc
FLAGS=-Wall -Wextra -Werror
OPTION_O= $(FLAGS) -c -I$(PATH_HLB)
OPTION_C= $(FLAGS) -o $(NAME) -I$(PATH_HDR) -I$(PATH_HLB) -L$(PATH_LIB)

all: $(NAME)

$(NAME):$(PATH_LIB) $(OBJ) $(PATH_HDR)
	make -C $(PATH_LIB)
	$(CC) $(OPTION_C) $(OBJ) -lft

%.o:$(PATH_SRC)%.c
	$(CC) $(OPTION_O) $^ -o $@

fcleanlib:
	make -C $(PATH_LIB) fclean

cleanlib:
	make -C $(PATH_LIB) clean

clean: cleanlib
	rm -f $(OBJ)

fclean: fcleanlib clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re fcleanlib cleanlib
