# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhyeong <junhyeong@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 19:47:40 by junhyeong         #+#    #+#              #
#    Updated: 2025/01/02 20:44:38 by junhyeong        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
INCDIR = ./inc
LIBDIR = ./lib
SRCDIR = ./src
LIBFTDIR = $(LIBDIR)
MLXDIR = $(LIBDIR)/mlx
OBJDIR = ./obj

# Files
SRC = $(SRC_DIR)/rt/canvas.c \
	$(SRC_DIR)/rt/hit.c \
	$(SRC_DIR)/rt/object_init.c \
	$(SRC_DIR)/rt/ray.c \
	$(SRC_DIR)/rt/run.c \
	$(SRC_DIR)/rt/scene.c \
	$(SRC_DIR)/rt/vec1.c \
	$(SRC_DIR)/rt/vec2.c \
	$(SRC_DIR)/rt/vec3.c
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/parse/parse_file.c \
	$(SRC_DIR)/parse/parse.c \
	$(SRC_DIR)/parse/parse_init.c \
	$(SRC_DIR)/parse/parse_object.c \
	$(SRC_DIR)/parse/parse_utils.c \
	$(SRC_DIR)/utils/utils.c \
	$(SRC_DIR)/utils/error.c \
	$(SRC_DIR)/utils/object.c \
	$(SRC_DIR)/utils/light.c

OBJS = $(SRC:%.c=$(OBJDIR)/%.o)
LIBFT = $(LIBFTDIR)/libft.a
MLX = $(MLXDIR)/libmlx.a

# Output
NAME = miniRT

# Commands
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft -lm -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR) -I$(MLXDIR) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(MLX):
	$(MAKE) -C $(MLXDIR)

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(MLXDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(MLXDIR) clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
