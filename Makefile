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
NAME = miniRT
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
INCDIR = ./inc
LIBDIR = ./lib
SRCDIR = ./src
LIBFTDIR = $(LIBDIR)
MLXDIR = $(LIBDIR)/mlx
OBJDIR = ./

# Files
SRC =	$(SRCDIR)/rt/canvas.c \
	$(SRCDIR)/rt/hit.c \
	$(SRCDIR)/rt/object_init.c \
	$(SRCDIR)/rt/ray.c \
	$(SRCDIR)/rt/run.c \
	$(SRCDIR)/rt/scene.c \
	$(SRCDIR)/rt/vec1.c \
	$(SRCDIR)/rt/vec2.c \
	$(SRCDIR)/rt/vec3.c \
	$(SRCDIR)/main.c \
	$(SRCDIR)/parse/parse_file.c \
	$(SRCDIR)/parse/parse.c \
	$(SRCDIR)/parse/parse_init.c \
	$(SRCDIR)/parse/parse_object.c \
	$(SRCDIR)/parse/parse_utils.c \
	$(SRCDIR)/utils/utils.c \
	$(SRCDIR)/utils/error.c \
	$(SRCDIR)/utils/object.c \
	$(SRCDIR)/utils/light.c 

OBJS = $(SRC:%.c=$(OBJDIR)/%.o)
LIBFT = $(LIBFTDIR)/libft.a
MLX = $(MLXDIR)/libmlx.a

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
