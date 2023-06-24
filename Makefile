
# .PHONY : all test norm clean fclean re

# NAME := cub3d.a
# SOFT_NAME := cub3D
# NAME_BONUS := cub3d_bonus.a
# SOFT_BONUS := cub3D_bonus

# CC := gcc
# FLAGS := -g3 -Wall -Wextra -Werror -I includes/ -I.. -MMD -MP
# SRC_DIR := sources/
# OBJ_DIR := objects/
# AR := ar rc
# RM := rm
# VAL := valgrind --leak-check=full --track-origins=yes


BLACK = \033[1;30m
REDBG = \033[30;41m
RED = \033[0;31m
GREEN = \033[0;32m
ORANGE = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
NC = \033[0m

# SRCS =	check_fd.c \
# 		ft_check_color.c \
# 		ft_direction.c \
# 		init.c \
# 		init_game.c \
# 		init_textures.c \
# 		init_map.c \
# 		parsing_map.c \
# 		util_cube3d.c \
# 		main.c \
# 		util_parse_fd.c \
# 		check_carte.c \


# BONUS =	

# LIBFT := libs/libft/libft.a

# FCLIB := ${MAKE} fclean -C libs/libft


# OBJS = $(SRCS:%.c=%.o)
# BOBJS = $(BONUS:%.c=%.o)
# NORM = $(wildcard *.c) $(wildcard *.h)

# OBJ = $(addprefix $(OBJ_DIR),$(OBJS))
# DEPS = $(OBJ:%.o=%.d)
# BOBJ = $(addprefix $(OBJ_DIR),$(BOBJS))
# DEPSB = $(BOBJ:%.o=%.d)

# OBJF := ${OBJ_DIR}.cache_exists

# all : ${SOFT_NAME}

# $(OBJF) :
# 	@mkdir -p ${OBJ_DIR}
# 	@touch ${OBJF}

# ${LIBFT} :
# 	${MAKE} all -C libs/libft

# 	@cp ${LIBFT} ${NAME}

# ${NAME} : ${OBJ}
# 	@echo "${BLUE}###${NC}Update de l'archive ${NAME}${BLUE}###${MAGENTA}"
# 	${AR} ${NAME} ${MLX} ${OBJ}
# 	@echo "${NC}"

# ${OBJ_DIR}%.o : %.c ${LIBFT} $(OBJF) Makefile
# 	@echo "${BLUE}###${NC}Creation du fichier ${@:%.c=%.o}${BLUE}###${ORANGE}"
# 	${CC} ${FLAGS} ${MLXFLAGS} -c $< -o $@
# 	@echo "${NC}"

# ${SOFT_NAME} : ${NAME}
# 	@echo "${BLUE}###${NC}Creation du fichier ${SOFT_NAME}${BLUE}###${ORANGE}"
# 	${CC} ${NAME} ${FLAGS} ${MLXFLAGS} -o ${SOFT_NAME}
# 	@echo "${NC}"

# bonus : ${SOFT_BONUS}

# ${SOFT_BONUS} : ${BOBJ}
# 	@echo "${BLUE}###${NC}Creation du fichier ${SOFT_BONUS}${BLUE}###${ORANGE}"
# 	${CC} ${BOBJ} ${LIBFT} ${FLAGS} ${MLXFLAGS} -o ${SOFT_BONUS}
# 	@echo "${NC}"

# clean : 
# 	${FCLIB}
# 	${CMLX}
# 	@echo "${RED}###${NC}Nettoyage des fichiers .o${RED}###"
# 	${RM} -rf ${OBJ_DIR} ${OBJF}
# 	@echo "${GREEN}###${NC}Nettoyage OK${GREEN}###${NC}\n"

# fclean : clean
# 	@echo "${RED}###${NC}Nettoyage d'archives et de Softs${RED}###"
# 	${RM} -f ${NAME} ${NAME_BONUS} ${SOFT_NAME} ${SOFT_BONUS}
# 	@echo "${GREEN}###${NC}Nettoyage OK${GREEN}###${NC}\n"

# re : fclean all

# norm :
# 	${MAKE} norm -C libs/libft
# 	@norminette $(NORM) | grep -v OK! || true

# -include ${DEPS} ${DEPSB}
                                                                                        

##present :
##		@echo "\e[1;42m     CUB3D !    \e[0m"

#################################-ARGUMENTS-####################################

NAME	= 	cub3D

FLAGS 	= 	-Wall -Werror -Wextra -g

CC 		= 	gcc

####################################-SOURCES-###################################

 SRC		= check_fd.c \
		ft_check_color.c \
		ft_direction.c \
		init.c \
		init_images.c \
		init_map.c \
		parsing_map.c \
		util_cube3d.c \
		main.c \
		util_parse_fd.c \
		check_carte.c \
		free.c \
		moves.c \
		moves2.c \
		render.c \
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