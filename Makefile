NAME = so_long

SOURCES = so_long.c get_maps.c check_map.c utils_sl.c window_management.c game_management.c \
		exit_free.c

OBJECTS = $(SOURCES:.c=.o)

#incluiremos los include -I aquí o en %.o=%.c
CFLAGS = -Wall -Werror -Wextra

CC = gcc -g 

LIBFT = libft/libft.h
MLX = minilibx/libmlx.h

INCLUDES = -I/Users/mirandacallejonhuertes/42cursus/so_long/minilibx/mlx

MLX_FLAGS = -L ./minilibx -lmlx -framework OpenGL -framework AppKit

LIBFT_FLAGS = -L ./libft -lft

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

all: $(NAME)

$(MLX):
	@$(MAKE) -C ./minilibx 
 
$(LIBFT):
	@$(MAKE) -C ./libft 
	
 $(NAME): $(OBJECTS) $(LIBFT) $(MLX) ./so_long.h
	$(CC) $(OBJECTS) $(MLX_FLAGS) -L ./libft -lft $(CFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJECTS) ./libft/obj
	@$(MAKE) -C ./minilibx clean

fclean: clean
	rm -rf $(NAME)
	@$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re