# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 14:43:07 by ebennamr          #+#    #+#              #
#    Updated: 2022/12/07 15:30:36 by ebennamr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############## Variable Block ###############

NAME := pipex
INCLIDE:=pipex.h
SRC :=error.c pipex.c
CC := cc
FLAGS:= -Wall -Wextra -Werror
LIB := libft/libft.a
OBJ = $(SRC:.c=.o)

############## Traget Block ###############

all : $(NAME)

$(NAME): makelib $(OBJ)
	@echo $(OBJ)
	$(CC) $(FLAGS) $(OBJ)  $(LIB) -o $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -c $^ -o $@
clean:
	rm -rf $(OBJ)
	cd libft ; make clean
fclean: clean
	rm -r $(NAME)
	rm -r $(LIB)
re: fclean all

makelib:
	cd libft ; make

