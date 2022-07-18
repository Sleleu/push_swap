NAME = push_swap

NAME_BONUS = checker

SRC = src/push_swap.c\
	  src/action.c\
	  src/error.c\
	  src/little_algo.c\
	  src/big_algo.c\
	  src/multiple_action.c\
	  src/get_data.c\
	  src/move.c\
	  src/utils.c\

SRC_BONUS = src_bonus/checker_bonus.c\
	   		src_bonus/action_bonus.c\
	   		src_bonus/multiple_action_bonus.c\
	   		src_bonus/error_bonus.c\
			src_bonus/move_bonus.c\

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : src/libft/libft.a $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L src/libft -lft -o $(NAME)

src/libft/libft.a:
	make -C src/libft

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)
	make clean -C src/libft
	make clean -C src_bonus/libft

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)
	make fclean -C src/libft
	make fclean -C src_bonus/libft

re: fclean all

bonus: $(NAME_BONUS)

$(NAME_BONUS) : src_bonus/libft/libft.a $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -L src_bonus/libft -lft -o $(NAME_BONUS)

src_bonus/libft/libft.a:
	make -C src_bonus/libft

norme:
	@echo "\033[35;32m\n\n === NORMINETTE PUSH SWAP === \n\n"
	@norminette src/
	@echo "\033[35;35m\n\n === NORMINETTE CHECKER === \n\n"
	@norminette src_bonus/
	@echo "\033[35;33m\n\n === NORMINETTE INCLUDES === \n\n"
	@norminette includes/

.PHONY: all clean fclean re norme bonus