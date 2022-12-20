# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 14:43:07 by ebennamr          #+#    #+#              #
#    Updated: 2022/12/18 16:22:09 by ebennamr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############## Variable Block ###############
NAME = pipex
FLAG = -Wall -Wextra -Werror
SRC	:=	mand/pipex.c mand/cmd.c lib/ft_strchr.c \
		lib/ft_strjoin.c \
		lib/ft_strlen.c \
		lib/ft_strncmp.c \
		lib/ft_substr.c \
		lib/error.c \
		lib/ft_split.c

INCLIDE = ./mand/pipex.h lib/lib.h

CC = gcc
OBJ = $(SRC:.c=.o)
########### shell color ############
GREEN:=\033[0;32m
RED =\033[0;31m
RESET =\033[0m
MARK = "✅"
REMOVE = "🗑"
############## Traget Block ###############
all : $(NAME)

$(NAME) :print $(OBJ)
	@echo "$(MARK)Object File Created"
	@$(CC) $(FLAG) $(OBJ) -o $(NAME)
	@echo "$(MARK)PIPEX Created"
%.o:%.c $(INCLIDE)
	@$(CC) $(FLAG) -c $< -o $@
	@echo "$(MARK) $@"



clean:
	@echo "$(RED) $(REMOVE) Rmove Oject Files $(RESET)"
	@rm -rf $(OBJ)


fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED) $(REMOVE) Remove $(NAME) $(RESET)"
	@echo "$(GREEN) Done $(RESET)"

re: fclean all

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
	@printf "$(GREEN)[+]🔸🔸🔸$(RED)MANDATORY🔹🔹🔹$(GREEN)[+]$(RESET)\n"

#.PHONY : re  all clean fclean


