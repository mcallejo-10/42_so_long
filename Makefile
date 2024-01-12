NAME = so_long

SOURCES = so_long.c get_maps.c check_map.c utils_sl.c 

OBJECTS = $(SOURCES:.c=.o)

#incluiremos los include -I aquí o en %.o=%.c∫
CFLAGS = -Wall #-Werror -Wextra

CC = cc -g

LIBFT = libft/libft.h
MLX = minilibx/libmlx.h

INCLUDES = -I/Users/mirandacallejonhuertes/42cursus/so_long/minilibx/mlx

MLX_FLAGS = -L ./minilibx -lmlx -framework OpenGL -framework AppKit

LIBFT_FLAGS = -L ./libft -lft

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(MLX):
	@$(MAKE) -C ./minilibx
	
 $(NAME): $(OBJECTS) $(LIBFT) $(MLX) ./so_long.h
	$(CC) $(OBJECTS) $(MLX_FLAGS) $(LIBFT_FLAGS) $(CFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJECTS) ./libft/obj @$(MAKE) -C clean ./minilibx

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re