# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/18 14:55:11 by junhyeop          #+#    #+#              #
#    Updated: 2025/01/18 19:34:51 by jihyjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

INCDIR = ./inc
LIBDIR = ./lib
SRCDIR = ./src
LIBFTDIR = $(LIBDIR)
MLXDIR = $(LIBDIR)/mlx

SRC =	$(SRCDIR)/main.c \
		$(SRCDIR)/parse/parse_file.c \
		$(SRCDIR)/parse/parse.c \
		$(SRCDIR)/parse/parse_init.c \
		$(SRCDIR)/parse/parse_object.c \
		$(SRCDIR)/parse/parse_utils.c \
		$(SRCDIR)/utils/utils.c \
		$(SRCDIR)/utils/error.c \
		$(SRCDIR)/utils/object.c \
		$(SRCDIR)/utils/light.c \
		$(SRCDIR)/rt/camera.c \
		$(SRCDIR)/rt/hit.c \
		$(SRCDIR)/rt/hit_cylinder.c \
		$(SRCDIR)/rt/hit_cone.c \
		$(SRCDIR)/rt/ray.c \
		$(SRCDIR)/rt/run.c \
		$(SRCDIR)/rt/vec1.c \
		$(SRCDIR)/rt/vec2.c \
		$(SRCDIR)/rt/vec3.c \
		$(SRCDIR)/rt/window.c \
		$(SRCDIR)/rt/light.c \
		$(SRCDIR)/rt/anti_alias.c \

OBJS = $(SRC:.c=.o)

LIBFT = $(LIBFTDIR)/libft.a
MLX = $(MLXDIR)/libmlx.dylib


CC				= cc
CFLAGS			= -Wall -Wextra -Werror
GL_LINK			= -lmlx -lm -L$(MLXDIR) -framework OpenGL -framework AppKit
FT_LINK			= -lft -L$(LIBFTDIR)
INCLUDES		= -I$(INC) -I$(MLXDIR) -I$(LIBFTDIR)
RM				= rm -f

all: $(NAME)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) $(FT_LINK) $(GL_LINK) $(INCLUDES) $(OBJS) -o $(NAME)
	@echo "$(NAME): object file and $(NAME) created"

$(LIBFT):
	@$(MAKE) -sC $(LIBFTDIR)
	@echo "$(NAME): $(LIBFT) created"

$(MLX):
	@$(MAKE) -sC $(MLXDIR)
	@echo "$(NAME): $(MLX) created"
clean:
	@$(MAKE) -sC $(MLXDIR) clean
	@$(MAKE) -sC $(LIBFTDIR) clean
	@$(RM) $(OBJS)
	@echo "$(NAME): objects deleted"

fclean: clean
	@$(RM) libmlx.dylib
	@$(RM) $(LIBFT)
	@$(RM) $(NAME)
	@echo "$(NAME): $(NAME), $(MLX), $(LIBFT) deleted"

re: fclean all

.PHONY: all clean fclean re
