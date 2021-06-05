# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/13 19:04:13 by bemoreau          #+#    #+#              #
#    Updated: 2021/06/05 09:48:26 by bemoreau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
INCLUDE =	checker.h\
			get_next_line.h\

INC_PATH = ./includes/

vpath %.c sources/

FILES =		./sources/main\
			./sources/get_next_line_utils\
			./sources/get_next_line\
			./sources/gnl_utils_2\
			./sources/realloc\
			./sources/parser\
			./sources/resolve\
			./sources/init_stack\
			./sources/operations\
			./sources/operations_2\

SRCS = $(addsuffix .c, $(FILES))
OBJ = $(SRCS:.c=.o)

CC = gcc
L_CC = clang
LIB = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror

### COLORS ###

NOC = \033[0m
BOLD = \033[1m
UNDERLINE = \033[4m
BLACK = \033[1;30m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
VIOLET = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m

all: 		LIBFT $(NAME)

LIBFT:
			@echo "$(CYAN)Building libft:$(NOC) $@"
			cd ./libft/ && make && cd ..

$(NAME): 	$(OBJ)
			@echo "$(CYAN)Constructing executable:$(NOC) $@"
			@$(L_CC) -g3 $(FLAGS) -o $(NAME) $(OBJ) $(LIB)

.c.o:		${SRCS}
			@echo " $(VIOLET)[$(L_CC)] $(GREEN)[$(FLAGS)]$(NOC) $(YELLOW)in progress ...:$(NOC) $< $(RED)->$(NOC) $@"
			@$(L_CC) -g3 $(FLAGS) -c -I$(INC_PATH) $< -o ${<:.c=.o}
clean:
	@echo "$(CYAN)Clean libft:$(NOC) $@"
	@cd libft && make clean && cd ..
	@echo "\n$(RED)Removing '.o' objects: $(NOC) $@"
	@rm -f $(OBJ)

fclean: clean
	@echo "$(CYAN)Fclean libft:$(NOC) $@"
	@cd libft && make fclean && cd ..
	@echo "\n$(RED)Removing executable: $(NOC) $@"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean MLX LIBFT
