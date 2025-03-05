NAME := cub3D 
.DEFAULT_GOAL := all
CC := cc
RM := rm -rf

################################################################################
###############                  DIRECTORIES                      ##############
################################################################################

OBJ_DIR := _obj
LIBFT_PATH := lib/lib_pri_get
LIBFT := $(LIBFT_PATH)/libftprintf.a
GARBAGE_PATH := lib/bin_malloc
GARBAGE := $(GARBAGE_PATH)/libgarbage.a
INC_DIRS := Includes $(LIBFT_PATH) $(GARBAGE_PATH)
SRC_DIRS := src

vpath %.h $(INC_DIRS)

################################################################################
###############                  SOURCE FILES                     ##############
################################################################################

SRC := $(shell find src -name '*.c')

################################################################################
###############               OBJECT FILES & RULES                ##############
################################################################################

OBJS := $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

# Compilation flags and linking options
CFLAGS := -Wall -Wextra -Werror -g $(addprefix -I, $(INC_DIRS)) -MMD -MP
LDFLAGS := -L$(LIBFT_PATH) -lftprintf -L$(GARBAGE_PATH) -lgarbage

# Submodule build rules
$(LIBFT):
	@echo "Building libft..."
	@$(MAKE) -C $(LIBFT_PATH)

$(GARBAGE):
	@echo "Building garbage collector..."
	@$(MAKE) -C $(GARBAGE_PATH)

# Main build target
all: $(NAME)

$(NAME): $(LIBFT) $(GARBAGE) $(OBJS)
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "\033[0;32m$(NAME) compiled successfully!\033[0m"

# Object file compilation
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

# Create object directory
$(OBJ_DIR):
	@echo "Creating $(OBJ_DIR) directory..."
	@mkdir -p $(OBJ_DIR)

# Clean targets
clean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(GARBAGE_PATH) clean

fclean: clean
	@echo "Removing $(NAME)..."
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(GARBAGE_PATH) fclean

re: fclean all

-include $(OBJS:%.o=%.d)

.PHONY: all clean fclean re