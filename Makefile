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

# Linux-specific frameworks and libraries
UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
    FRAMEWORKS := -lglfw -lGL -lX11 -ldl -lpthread -lm
else
    FRAMEWORKS := -ldl -lglfw -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit
endif

# Submodule initialization
SUBMODULES := $(LIBFT_PATH) $(GARBAGE_PATH) $(MLX42_PATH)

# Ensure submodules are initialized
submodules:
	@echo "\033[0;32mInitializing submodules...\033[0m"
	@git submodule update --init --recursive

# Install dependencies for Linux
install-deps:
	@echo "\033[0;32mInstalling dependencies...\033[0m"
	@if [ "$(UNAME)" = "Linux" ]; then \
		sudo apt update; \
		sudo apt install -y build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev libglu1-mesa-dev libxi-dev libxrandr-dev libxinerama-dev libxcursor-dev; \
	else \
		echo "Dependency installation is only supported on Linux."; \
	fi

# Submodule build rules
$(LIBFT): | submodules
	@echo "\033[0;32mBuilding libft...\033[0m"
	@$(MAKE) -C $(LIBFT_PATH)

$(GARBAGE): | submodules
	@echo "\033[0;32mBuilding garbage collector...\033[0m"
	@$(MAKE) -C $(GARBAGE_PATH)

$(MLX42): | submodules
	@echo "\033[0;32mBuilding MLX42...\033[0m"
	@mkdir -p $(MLX42_PATH)/build
	@cd $(MLX42_PATH)/build && cmake ..
	@$(MAKE) -C $(MLX42_PATH)/build

# Main build target
all: submodules $(NAME)

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

.PHONY: all clean fclean re install-deps submodules