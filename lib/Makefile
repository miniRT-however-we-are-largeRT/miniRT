# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhyeong <junhyeong@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 21:10:00 by junhyeong         #+#    #+#              #
#    Updated: 2025/01/02 20:37:46 by junhyeong        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libft.a
FTPFDIR     = ./ft_printf/
GNLDIR      = ./get_next_line/
INCDIRS     = ./ $(FTPFDIR) $(GNLDIR)

CC          = gcc
AR          = ar
CFLAGS      = -Wall -Wextra -Werror $(foreach D, $(INCDIRS), -I$(D))
ARFLAGS     = rs

SRCS        = ft_memset.c \
              ft_bzero.c \
              ft_memcpy.c \
              ft_memcpy.c \
              ft_memmove.c \
              ft_memchr.c \
              ft_memcmp.c \
              ft_strcmp.c \
              ft_strlen.c \
              ft_strlcpy.c \
              ft_strlcat.c \
              ft_strchr.c \
              ft_strrchr.c \
              ft_strnstr.c \
              ft_strncmp.c \
              ft_atoi.c \
              ft_isalpha.c \
              ft_isdigit.c \
              ft_isalnum.c \
              ft_isascii.c \
              ft_isprint.c \
              ft_toupper.c \
              ft_tolower.c \
              ft_calloc.c \
              ft_substr.c \
              ft_strjoin.c \
              ft_strtrim.c \
              ft_split.c \
              ft_itoa.c \
              ft_strmapi.c \
              ft_putchar_fd.c \
              ft_putstr_fd.c \
              ft_putendl_fd.c \
              ft_putnbr_fd.c \
              ft_strdup.c \
              ft_striteri.c \
              my_strjoin.c \
              ft_split_utils.c \
              ft_atof.c

SRCS_FTPF   = ft_printf.c ft_itoa_hex.c ft_itoa.c printf_option.c printf_option_2.c printf_utils.c
SRCS_GNL    = get_next_line.c get_next_line_utils.c

SRCS        += $(foreach D, $(SRCS_FTPF), $(FTPFDIR)$(D)) \
               $(foreach D, $(SRCS_GNL), $(GNLDIR)$(D))

OBJS        = $(SRCS:.c=.o)

# Colors for better output
RESET       = \033[0m
GREEN       = \033[32m
YELLOW      = \033[33m
BLUE        = \033[34m

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)Archiving$(RESET): Creating $(NAME)"
	@$(AR) $(ARFLAGS) $(NAME) $^
	@echo "$(GREEN)Build complete!$(RESET) $(NAME) is ready."

%.o: %.c $(foreach D, $(INCDIRS), $(D)*.h)
	@echo "$(YELLOW)Compiling$(RESET): $<"
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@echo "$(BLUE)Cleaning$(RESET): Object files"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(BLUE)Cleaning$(RESET): $(NAME)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
