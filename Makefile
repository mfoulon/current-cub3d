NAME = cub3d

LIBFT		:= ./libft/libft.a
LIBFT_PATH	:= "libft"

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx
else
	INCLUDES = -I/opt/X11/include -Imlx
endif

RM = rm
RMFLAG = -f

MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

SRCS = \
	error.c \
	free.c \
	hooks.c \
	init_map.c \
	main.c \
	move.c \
	parse_utils.c \
	parse.c \
	player.c \
	ray.c \
	render.c \
	solver.c \
	textures.c \
	textures_utils.c \
	window.c

OBJS = $(SRCS:.c=.o)

all: $(MLX_LIB) $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -lft $(MLX_FLAGS)

$(MLX_LIB):
	@make -C $(MLX_DIR)

clean:
	@make clean -C $(LIBFT_PATH)
	$(RM) $(RMFLAG) $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	$(RM) $(RMFLAG) $(NAME)
	if [ -d "./mlx" ]; then make -C $(MLX_DIR) clean; fi

re: fclean all

.PHONY: all clean run fclean re 