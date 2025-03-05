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
MLX42_PATH := lib/MLX42
MLX42 := $(MLX42_PATH)/build/libmlx42.a
INC_DIRS := Includes $(LIBFT_PATH) $(GARBAGE_PATH) $(MLX42_PATH)/include
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
LDFLAGS := -L$(LIBFT_PATH) -lftprintf -L$(GARBAGE_PATH) -lgarbage -L$(MLX42_PATH)/build -lmlx42
FRAMEWORKS := -ldl -lglfw -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit

# Submodule initialization
SUBMODULES := $(LIBFT_PATH) $(GARBAGE_PATH) $(MLX42_PATH)

$(SUBMODULES):
	@git submodule update --init --recursive

# Submodule build rules
$(LIBFT): | $(SUBMODULES)
	@echo "\033[0;32mBuilding libft...\033[0m"
	@$(MAKE) -C $(LIBFT_PATH)

$(GARBAGE): | $(SUBMODULES)
	@echo "\033[0;32mBuilding garbage collector...\033[0m"
	@$(MAKE) -C $(GARBAGE_PATH)

$(MLX42): | $(SUBMODULES)
	@echo "\033[0;32mBuilding MLX42...\033[0m"
	@cmake -B $(MLX42_PATH)/build -S $(MLX42_PATH)
	@$(MAKE) -C $(MLX42_PATH)/build

# Main build target
all: $(NAME)

$(NAME): $(LIBFT) $(GARBAGE) $(MLX42) $(OBJS)
	@echo "\033[0;32mLinking $(NAME)...\033[0m"
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(FRAMEWORKS) -o $(NAME)
	@echo "\033[0;32m$(NAME) compiled successfully!\033[0m"

# Object file compilation
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

# Create object directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Clean targets
clean:
	@echo "\033[0;31mCleaning object files...\033[0m"
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(GARBAGE_PATH) clean
	@$(MAKE) -C $(MLX42_PATH)/build clean

fclean: clean
	@echo "\033[0;31mRemoving $(NAME)...\033[0m"
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(GARBAGE_PATH) fclean
	@$(RM) $(MLX42_PATH)/build

re: fclean all

-include $(OBJS:%.o=%.d)

.PHONY: all clean fclean re