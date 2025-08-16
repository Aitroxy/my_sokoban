##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC = 	my_sokoban.c \
		my_strncmp.c \
		memset.c \
		my_strwa/my_strwa.c \
		my_strwa/clean_string.c \
		my_strwa/my_strcpy.c \
		my_strwa/my_token_strlen.c \
		error_case.c \
		usage.c \
		handle_map.c \
		my_strwa/my_strdup.c \
		move.c \
		handle_box.c \
		free_all.c \
		my_arraydup.c \
		my_array_len.c \
		check_win.c \
		check_boxs_block.c

OBJ = $(SRC:.c=.o)

CFLAGS = -W -Werror -Wall -Wextra -I./include -g3 -lncurses

NAME = my_sokoban

all : $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean :
	rm -f $(OBJ)
	rm -f #*
	rm -f *~

fclean : clean
	rm -f $(NAME)

re : fclean all
