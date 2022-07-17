NAME = push_swap

SRC = src/push_swap.c\
	  src/action.c\
	  src/error.c\
	  src/little_algo.c\
	  src/big_algo.c\
	  src/multiple_action.c\
	  src/get_data.c\

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)


$(NAME) : src/libft/libft.a $(OBJ)
	$(CC) -g3 $(CFLAGS) $(OBJ) -L src/libft -lft -o $(NAME)

src/libft/libft.a:
	make -C src/libft

clean:
	rm -rf $(OBJ)
	make clean -C src/libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C src/libft

re: fclean all

norme:
	@echo "\033[35;36m\n\n === NORMINETTE LIBFT === \n\n"
	norminette src/libft
	@echo "\033[35;32m\n\n === NORMINETTE PUSH SWAP === \n\n"
	norminette src/push_swap.c

.PHONY: all clean fclean re norme