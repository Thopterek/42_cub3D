NAME = libftprintf.a
SRCS = \
	ft_printf.c \
	ft_uns_itoa.c \
	ft_hex_itoa.c \
	ft_ptr_itoa.c \
	get_next_line.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra #-Werror
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
INC_DIRS = -I$(LIBFT_DIR)

# The rule to build the project
all: $(LIBFT) $(NAME)

# Compiling libft first
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Compiling ft_printf
$(NAME): $(OBJS) $(LIBFT)
	@ar rcs $(NAME) $(OBJS) $(LIBFT_DIR)/*.o

# Rule to compile .c files into .o files
%.o: %.c
	@$(CC) $(CFLAGS) $(INC_DIRS) -c $< -o $@

# Cleaning object files in both projects
clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

# Full clean
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re