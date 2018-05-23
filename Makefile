# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 16:31:48 by uboumedj          #+#    #+#              #
#    Updated: 2018/05/23 19:08:08 by uboumedj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

SRCS = srcs/ft_ls.c srcs/errors.c 

INC = ft_ls.h

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@ $(CC) $(FLAGS) -o $(NAME) -Iinclude $(LIBFT)/libft.a $(SRCS)
	@echo "\033[1;34mft_ls\033[1;32m...compiled\t✓\033[0m"

clean:
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT)
	@echo "\033[1;34mft_ls project\033[1;33m obj files removed\t\033[1;31m✓\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT)
	@echo "\033[1;34mft_ls project\033[1;33m files deleted\t\t\033[1;31m✓\033[0m"

re: fclean all
