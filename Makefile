# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 16:31:48 by uboumedj          #+#    #+#              #
#    Updated: 2018/10/05 16:32:59 by uboumedj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc

FLAGS = -Wall -Wextra -Werror -fsanitize=address,undefined

LIBFT = libft

SRCS = srcs/ft_ls.c srcs/errors.c srcs/file_parsing.c srcs/file_manipulation.c \
		srcs/data_initialisation.c srcs/reorder.c srcs/reorder_help_funcs.c \
		srcs/free_memory.c srcs/display.c srcs/parse_args.c \
		srcs/file_requests_parsing.c srcs/parsing_help_funcs.c \
		srcs/display_requested_files.c srcs/parsing_help_funcs_2.c \
		srcs/display_help_funcs.c srcs/display_help_funcs_2.c

INC = ft_ls.h

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@ $(CC) $(FLAGS) -o $(NAME) $(SRCS) -Iinclude $(LIBFT)/libft.a
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
