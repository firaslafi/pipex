# Compiler and flags
CC = cc
# CFLAGS = -Wall -Wextra -Werror

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