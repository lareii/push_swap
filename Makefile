NAME		= push_swap

CFLAGS		= -Wall -Wextra -Werror -Ilib/libft
LDFLAGS		= -Llib/libft
LDLIBS		= -lft
RM			= rm -rf

BUILD_DIR	= build
VPATH		= src
SRCS		= check_args.c utils.c push_swap.c sorts.c sorts_small.c operations.c
OBJS		= $(addprefix $(BUILD_DIR)/,$(SRCS:.c=.o))

all: libft $(NAME)

libft:
	@make -C lib/libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS) $(LDLIBS)

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C lib/libft clean
	$(RM) $(BUILD_DIR)

fclean: clean
	@make -C lib/libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft