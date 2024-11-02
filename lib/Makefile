NAME        = libmlx42.a

CC          = cc
RM          = rm -f
CLONE       = git clone --depth=1

# Update the include path for MLX42 headers
CFLAGS      += -Wall -Wextra -Werror -O3 -I$(MLX)/includes -I$(MLX)/includes/MLX42  
CLINKS      = -ldl -lglfw -pthread -lm

MLX         = minilibx
LIBMLX      = $(MLX)/libmlx42.a

SRC         = $(wildcard minilibx/src/*.c)  # Collect all .c files from src
OBJ         = $(SRC:.c=.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(LIBMLX) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBMLX) $(CLINKS)

$(LIBMLX): $(MLX)
	$(MAKE) -C $(MLX)

$(MLX):
	$(CLONE) https://github.com/kodokaii/MLX42.git $(MLX)
	cmake $(MLX) -B $(MLX)

%.o: src/%.c  # Specifying the location of source files
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C $(MLX)

fclean: clean
	$(RM) $(LIBMLX)
	$(RM) $(NAME)

clear: fclean
	$(RM) -r $(MLX) 

re: fclean all

.PHONY: all bonus clear clean fclean re
