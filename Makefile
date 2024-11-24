NAME			= push_swap
LIBFT			= libft.a
LIBFT_DIR	= lib/libft

CFLAGS		= -Wall -Wextra -Werror -I$(LIBFT_DIR) -Iinclude
RM				= rm -rf

BUILD_DIR	= build
VPATH			= src
SRCS			= main.c
OBJS			= $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/$(LIBFT) -o $(NAME)

clean:
	$(RM) $(BUILD_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re