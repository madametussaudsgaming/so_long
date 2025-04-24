# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 18:33:54 by rpadasia          #+#    #+#              #
#    Updated: 2025/04/23 19:07:14 by rpadasia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_isdigit.c ft_memmove.c ft_split.c ft_strlcpy.c ft_strtrim.c ft_bzero.c ft_isprint.c\
ft_memset.c ft_strchr.c ft_strlen.c ft_substr.c ft_calloc.c ft_itoa.c ft_putchar_fd.c ft_strdup.c ft_strmapi.c\
ft_tolower.c ft_isalnum.c ft_memchr.c ft_putendl_fd.c ft_striteri.c ft_strncmp.c ft_toupper.c ft_isalpha.c ft_memcmp.c\
ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c ft_isascii.c ft_memcpy.c ft_putstr_fd.c ft_strlcat.c ft_strrchr.c

SRCB = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

GNL_SRC = get_next_line/get_next_line_bonus.c get_next_line/get_next_line_utils_bonus.c
PRINTF_SRC = ft_printf/ft_printf.c ft_printf/ft_print_d.c ft_printf/ft_print_c.c ft_printf/ft_print_p.c ft_printf/ft_print_s.c ft_printf/ft_print_u.c ft_printf/ft_print_x.c

GNL_OBJ = $(GNL_SRC:%.c=%.o)
PRINTF_OBJ = $(PRINTF_SRC:%.c=%.o)

OBJ = $(SRC:%.c=%.o) $(GNL_OBJ) $(PRINTF_OBJ)
OBJB = $(SRCB:%.c=%.o)
CC = gcc
RM = rm -f
LIBC = ar rcs
CFLAGS = -Wall -Wextra -Werror -I.

all: $(NAME)

$(NAME): $(OBJ)
	$(LIBC) $(NAME) $(OBJ)

bonus: $(NAME) $(OBJB)
	$(LIBC) $(NAME) $(OBJB)

%.o: %.c
	$(CC) $(CFLAGS) -I get_next_line -I ft_printf -fPIC -c $< -o $@

so: $(OBJ) $(OBJB)
	$(CC) -nostartfiles -fPIC -shared -o $(SO_NAME) $(OBJ) $(OBJB)

clean:
	$(RM) $(OBJ) $(OBJB)

fclean: clean
	$(RM) $(NAME) $(SO_NAME)

re: fclean all

.PHONY: all bonus clean fclean re so
