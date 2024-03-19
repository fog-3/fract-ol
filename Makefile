NAME = fractol

# Compilers
CC = gcc
CFLAGS = -Werror -Wextra -Wall

# MinilibGX
MLX_PATH = minilibx-linux/
MLX_NAME = libmlx.a
MLX = $(MLX_PATH)$(MLX_NAME)


# Libft
LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# Includes
INC = -I ./includes/\
      -I ./libft/\
      -I ./minilibx-linux/

# Sources

SRC_PATH = src/
SRC = main.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))


# Objects
OBJ_PATH = obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)
	@mkdir $(OBJ_PATH)fractal_sets/
	@mkdir $(OBJ_PATH)color_schemes/

$(MLX):
	@echo "Compiling Minilibx..."
	@make -sC $(MLX_PATH)
	@echo "-------------- ✅ MiniLibx Compiled ✅ -------------"

$(LIBFT):
	@echo "Compiling libft..."
	@make -sC $(LIBFT_PATH)
	@echo "-------------- ✅ Libft Compiled ✅ -------------"

$(NAME): $(OBJS)
	@echo "Compiling fractol..."
	@$(cc) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC) -lXext -lX11 -lm
	@echo "-------------- ✅ Fractol is ready ✅ -------------"

bonus: all

clean:
	@echo "Removing .o object files..."
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@echo "Removing fractol.."
	@rm .f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: all re clean fclean
