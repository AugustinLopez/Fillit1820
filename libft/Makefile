# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aulopez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 13:11:21 by aulopez           #+#    #+#              #
#    Updated: 2018/12/03 15:16:32 by aulopez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

TARGETS=memset bzero memcpy memccpy memmove \
		memchr memcmp strlen strdup strcpy \
		strncpy strcat strncat strlcat strchr \
		strrchr strstr strnstr strcmp strncmp \
		atoi isalpha isdigit isalnum isascii \
		isprint toupper tolower \
		memalloc memdel strnew strdel strclr \
		striter striteri strmap strmapi strequ \
		strnequ strsub strjoin strtrim strsplit \
		itoa putchar putstr putendl putnbr \
		putchar_fd putstr_fd putendl_fd putnbr_fd \
		lstnew lstdelone lstdel lstadd lstiter lstmap \
		puthex puthex_fd strrstr rand sqrt pow abs min max lstpush lstsize \
		putbit_i32 lstfree

NO_FT_TARGETS=get_next_line

PATH_SRC=
PATH_HDR=./includes

SRC=$(patsubst %,$(PATH_SRC)ft_%.c,$(TARGETS)) $(NO_FT_TARGETS:%=%.c)
OBJ=$(SRC:.c=.o)

CC=gcc
FLAGS=-Wall -Wextra -Werror
OPTION= -c -I$(PATH_HDR)

all: $(NAME)

$(NAME): $(OBJ) $(PATH_HDR)
	ar rcs $(NAME) $(OBJ)

%.o:%.c
	$(CC) $(FLAGS) $(OPTION) $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
