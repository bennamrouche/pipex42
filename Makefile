# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 14:43:07 by ebennamr          #+#    #+#              #
#    Updated: 2022/12/14 15:39:47 by ebennamr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############## Variable Block ###############

NAME := pipex
INCLIDE:=pipex.h error.h
SRC :=error.c pipex.c cmd.c
CC := cc
FLAGS:= -Wall -Wextra -Werror
LIB := libft/libft.a
OBJ = $(SRC:.c=.o)
GREEN:=\033[0;32m
RED:=\033[0;31m
RESET:=\033[0m
MARK := "✅"
############## Traget Block ###############

all : $(NAME)

$(NAME): print makelib $(OBJ)
	@echo "Object File Created$(MARK)"
	@$(CC) $(FLAGS) $(OBJ)  $(LIB) -o $(NAME)
	@echo "PIPEX Created $(MARK)"
%.o:%.c
	@$(CC) $(FLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJ)
	cd libft ; make clean
fclean: clean
	rm -r $(NAME)
	rm -r $(LIB)
re: fclean all

makelib:
	@cd libft ; make
	@echo "libft Created $(MARK)"
cleanlib:
	cd libft ; make fclean;
print:
	@printf "====================================================\n"
	@printf "$(GREEN)  @@@@@  $(RED)  @@@@@@@@@  $(GREEN)  @@@@@   $(RED) @@@@@@@@ $(GREEN) @@     @@\n"
	@printf "$(GREEN)  @   @@ $(RED)      @@     $(GREEN)  @   @@  $(RED) @        $(GREEN) @@@@  @@@\n"
	@printf "$(GREEN)  @  @@@ $(RED)      @@     $(GREEN)  @  @@@  $(RED) @        $(GREEN)    @ @@\n"
	@printf "$(GREEN)  @@@@   $(RED)      @@     $(GREEN)  @@@@    $(RED) @@@@@@@  $(GREEN)     @@\n"
	@printf "$(GREEN)  @      $(RED)      @@     $(GREEN)  @       $(RED) @        $(GREEN)    @@@\n"
	@printf "$(GREEN)  @      $(RED)      @@     $(GREEN)  @       $(RED) @        $(GREEN)   @@ @@\n"
	@printf "$(GREEN)  @      $(RED)      @@     $(GREEN)  @       $(RED) @        $(GREEN) @@@   @@@\n"
	@printf "$(GREEN)@@@@@@   $(RED)  @@@@@@@@@  $(GREEN)@@@@@@    $(RED) @@@@@@@  $(GREEN) @@     @@\n"
	@printf "$(RESET)====================================================\n"


