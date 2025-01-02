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

NAME        = minirt

SRC_DIR     = ./src
LIBDIR      = ./lib/
LIBNAME     = ft
LIB         = $(LIBDIR)lib$(LIBNAME).a
INCDIRS     = ./inc

SRC         = $(SRC_DIR)/main.c \
              $(SRC_DIR)/parse/parse_file.c \
              $(SRC_DIR)/parse/parse.c \
              $(SRC_DIR)/parse/parse_init.c \
              $(SRC_DIR)/parse/parse_object.c \
              $(SRC_DIR)/parse/parse_utils.c \
              $(SRC_DIR)/utils/utils.c \
              $(SRC_DIR)/utils/error.c \
              $(SRC_DIR)/utils/object.c \
              $(SRC_DIR)/utils/light.c

OBJS        = $(SRC:.c=.o)

CC          = gcc
MAKE        = make
RM          = rm -f
CFLAGS      = -Wall -Wextra -Werror $(foreach D, $(INCDIRS), -I$(D))
READFLAGS   = -lm

# Colors for better output
RESET       = \033[0m
GREEN       = \033[32m
YELLOW      = \033[33m
BLUE        = \033[34m

all: $(NAME)

%.o: %.c $(foreach D, $(INCDIRS), $(D)*.h)
	@echo "$(YELLOW)Compiling$(RESET): $<"
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(LIB) $(OBJS)
	@echo "$(BLUE)Linking$(RESET): Creating $(NAME)"
	@$(CC) -o $(NAME) $(OBJS) -L$(LIBDIR) -l$(LIBNAME) $(READFLAGS)
	@echo "$(GREEN)Build complete!$(RESET) $(NAME) is ready."

$(LIB):
	@echo "$(YELLOW)Building library$(RESET): $(LIBNAME)"
	@$(MAKE) -C $(LIBDIR) all

clean:
	@echo "$(BLUE)Cleaning$(RESET): Object files"
	@$(MAKE) -C $(LIBDIR) clean
	@$(RM) $(OBJS)

fclean: clean
	@echo "$(BLUE)Cleaning$(RESET): $(NAME)"
	@$(MAKE) -C $(LIBDIR) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
