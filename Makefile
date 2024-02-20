#COLORS#
GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m
YELLOW=\033[1;33m

NAME = so_long

SOURCES = main.c get_maps.c check_map.c utils_sl.c window_management.c game_management.c \
		exit_free.c

OBJECTS = $(SOURCES:%.c=%.o)

CFLAGS = -Wall -Werror -Wextra -I./

CC = gcc

LIBFT = my_libft/lft.h
MLX = minilibx/libmlx.h

MLX_FLAGS = -L ./minilibx -lmlx -framework OpenGL -framework AppKit 

LIBFT_FLAGS = -L ./my_libft -lft

%.o: %.c 
	$(CC) -c $< $(CFLAGS)  -o $@
	@echo "$(YELLOW)Compiling... $(END)$(patsubst $(DIR_BUILD)%,%,$@)"

all: $(MLX) $(LIBFT) $(NAME)

$(MLX):
	@$(MAKE) -C ./minilibx --no-print-directory

$(LIBFT):
	@$(MAKE) -C ./my_libft --no-print-directory

$(NAME): Makefile $(SOURCES)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(SOURCES) $(LIBFT_FLAGS) -o $(NAME)
	@echo "$(GREEN)SO_LONG DONE$(END)"

clean:
	@rm -rf $(OBJECTS) 
	@$(MAKE) -C ./my_libft clean --no-print-directory
	@$(MAKE) -C ./minilibx clean --no-print-directory 

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C ./my_libft fclean --no-print-directory
	@$(MAKE) -C ./minilibx fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re
