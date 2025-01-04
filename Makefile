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

# Subdirectories
RTDIR = rt
PARSEDIR = parse
UTILSDIR = utils

# Source files
SRC =	$(SRCDIR)/main.c \
		$(SRCDIR)/parse/parse_file.c \
		$(SRCDIR)/parse/parse.c \
		$(SRCDIR)/parse/parse_init.c \
		$(SRCDIR)/parse/parse_object.c \
		$(SRCDIR)/parse/parse_utils.c \
		$(SRCDIR)/utils/utils.c \
		$(SRCDIR)/utils/error.c \
		$(SRCDIR)/utils/object.c \
		$(SRCDIR)/utils/light.c

# Object files
OBJS = $(SRC:.c=.o)

# Library files
LIBFT = $(LIBFTDIR)/libft.a
MLX = $(MLXDIR)/libmlx.a

# Commands
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft -lm -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(MLX):
	$(MAKE) -C $(MLXDIR)

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(MLXDIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
