# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
INCDIR = ./inc
LIBDIR = ./lib
SRCDIR = ./srcs
LIBFTDIR = $(LIBDIR)/libft
MLXDIR = $(LIBDIR)/mlx
OBJDIR = ./obj

# Files
SRC = main.c ray.c run.c vec1.c vec2.c vec3.c
OBJS = $(SRC:%.c=$(OBJDIR)/%.o)
LIBFT = $(LIBFTDIR)/libft.a
MLX = $(MLXDIR)/libmlx.a

# Output
NAME = miniRT

# Commands
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

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
