

##################################-COLORS-#####################################

BLACK = \033[1;30m
REDBG = \033[30;41m
RED = \033[0;31m
GREEN = \033[0;32m
ORANGE = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
NC = \033[0m


#################################-ARGUMENTS-####################################

NAME	= 	cub3D

FLAGS 	= 	-Wall -Werror -Wextra -g

CC 		= 	gcc

####################################-SOURCES-###################################

 SRC		= check_fd.c \
		ft_check_color.c \
		ft_check_color2.c \
		ft_direction.c \
		init.c \
		init_images.c \
		init_map.c \
		parsing_map.c \
		parsing_map2.c \
		parsing_map3.c \
		util_cube3d.c \
		main.c \
		util_parse_fd.c \
		check_carte.c \
		free.c \
		moves.c \
		moves2.c \
		raycasting.c \
		raycasting_2.c \
		display.c \
		textures_init.c \
			
####################################-OBJECTS-###################################

#OBJ_PATH	= obj
#OBJ		= $(addprefix $(OBJ_PATH), $(SRC:.c=.o))
OBJS		= $(SRC:.c=.o)

####################################-RULES-#####################################

# Minilibx
MLX_PATH	= minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

# Libft
LIBFT_PATH	= libs/libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# Includes
INC			=	-I ./cub3d.h

all:  $(NAME)

${NAME}: ${OBJS}
	@echo "Making MiniLibX..."
	@make -sC $(MLX_PATH)
	@echo "Making libft..."
	@make -sC $(LIBFT_PATH)
	@echo "Making cub3d..."
	$(CC) $(FLAGS) $(OBJS) -L./libs/libft/ -lft -L./minilibx-linux -lmlx -lXext -lX11 -lm -lz -o $(NAME)
	@echo "cub3d ready!"

RM		=  rm -f

%.o: %.c
#@mkdir -p $(OBJ_PATH)
	@$(CC) $(FLAGS)  -c $< -o $@ 


clean:
		$(RM) ${OBJS}
		make clean -C $(MLX_PATH)
		make clean -C $(LIBFT_PATH)

fclean:	clean
	@echo "spring cleaning..."
	@$(RM) ${NAME}

re: 		fclean all

.PHONY: 	all clean fclean re