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

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(MLX_LIB) $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR) all

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean -s

re: fclean all

.PHONY: all clean fclean re
