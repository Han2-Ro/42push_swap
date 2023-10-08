CC = cc
CFLAGS = -Wall -Wextra -Werror -g
OBJ_DIR = objs
SRCS = main.c exec_operation.c rec_brootforce.c push_swap_utils.c
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))
NAME = push_swap

SRCS_BONUS = checker.c exec_operation.c rec_brootforce.c push_swap_utils.c
OBJS_BONUS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS_BONUS))
NAME_BONUS = checker

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -o $(NAME)

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJS_BONUS) -L./libft -lft -o $(NAME_BONUS)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean bonus