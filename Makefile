# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/04 18:49:20 by kmykhail          #+#    #+#              #
#    Updated: 2018/07/10 12:02:50 by kmykhail         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = kmykhail.filler

SRC_NAME = main.c check_map.c gnl_filler.c helper_filler.c shape.c touch.c which_way.c filler_formula.c fill_arr.c \
	  	helper_check_map.c 

OBJC = $(SRC_NAME:%.c = srcs/%.o)

OBJO = $(SRC_NAME:.c=.o)

FLAGS = -Wall -Werror -Wextra

CC = gcc

LIBDIR = libft

%.o: srcs/%.c
	@$(CC) $(FLAGS) -c $< -I includes

all: $(NAME)

$(NAME): $(OBJO)
	@make -C $(LIBDIR)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJO) -L./$(LIBDIR) -lft -I includes
	@echo "\033[3;36mfiller has been made\033[0m"
clean:
	@make clean -C $(LIBDIR)
	@rm -f $(OBJO)
fclean: clean
	@make clean -C $(LIBDIR)
	@rm -f $(NAME)

re: fclean all
