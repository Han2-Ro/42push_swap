CC = cc
CFLAGS = -Wall -Wextra -Werror -g
OBJ_DIR = objs
SRCS = main.c exec_operation.c
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))
NAME = push_swap

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -o $(NAME)

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rmdir OBJ_DIR

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean