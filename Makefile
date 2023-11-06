CC = cc
CFLAGS = -g -Wall -Wextra -Werror
SRC_DIR = src
OBJ_DIR = objs
SRCS = main.c init_stacks.c exec_operation.c push_swap_utils.c string_utils.c quicksort.c convert_stack.c calculate_solution.c# rec_brootforce.c
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))
NAME = push_swap

SRCS_BONUS = checker.c exec_operation.c push_swap_utils.c init_stacks.c string_utils.c
OBJS_BONUS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS_BONUS))
NAME_BONUS = checker

all: $(NAME) $(NAME_BONUS)

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJS_BONUS) -L./libft -lft -o $(NAME_BONUS)

clean:
	make clean -C ./libft
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean bonus