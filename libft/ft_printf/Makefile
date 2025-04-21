NAME = libftprintf.a

SRC = ft_print_c.c ft_printf.c ft_print_p.c ft_print_u.c ft_print_d.c ft_print_s.c ft_print_x.c
OBJ = $(SRC:%.c=%.o)
CC = gcc
LIBC = ar rcs
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(LIBC) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f  $(OBJ)

fclean: clean
	rm -f  $(NAME) 

re: fclean all

.PHONY: all clean fclean re so
