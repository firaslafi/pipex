# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flafi <flafi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 16:38:00 by flafi             #+#    #+#              #
#    Updated: 2023/10/13 16:39:29 by flafi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
# CFLAGS = -Wall -Wextra -Werror

.SILENT:
# Source and output files
SRC = pipex.c
LIBFT = libft/libft.a
NAME = pipex

# Targets
all: $(NAME)

$(NAME): $(SRC) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIBFT)


$(LIBFT):
	make -C libft

clean:
	make -C libft clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re