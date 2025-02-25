SRCS =	main.c						\
		utils.c						\
		map_parsing.c				\
		map_checking.c				\
		map_connecting_checking.c	\
		edge_checking.c				\
		element_parsing.c			\
		element_checking.c			\
		graphic_management.c		\
		heap_cleanup.c				\
		drawing.c					\
		game_hook.c					\
		vector_init.c				\
		raycasting.c

OBJS = $(SRCS:.c=.o)

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

NAME = cub3D

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@make -C mlx_linux
	cp libft/libft.a .
	$(CC) $(CFLAGS) $(OBJS) libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@make clean -C libft

clean:
	@make clean -C libft
	@make clean -C mlx_linux
	$(RM) $(OBJS)

fclean: clean
	@make fclean -C libft
	@make clean -C mlx_linux
	$(RM) $(NAME) libft.a cub3D.a

re: fclean all

.PHONY: all clean fclean re
