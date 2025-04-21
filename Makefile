# Makefile for so_long (Linux)

NAME        = so_long
CC          = cc
CFLAGS      = -Wall
MLX_DIR     = ./mlx
MLX_LIB     = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -lXext -lX11 -lm
SRC_DIR     = src
OBJ_DIR     = obj
INCLUDE     = -I includes -I $(MLX_DIR)

SRCS        = $(wildcard $(SRC_DIR)/*.c)
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(MLX_LIB):
	@make -C $(MLX_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
