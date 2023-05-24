# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hferjani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/03 14:18:35 by hferjani          #+#    #+#              #
#    Updated: 2023/05/24 12:52:44 by hferjani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##present :
##		@echo "\e[1;42m     CUB3D !    \e[0m"

#################################-ARGUMENTS-####################################

NAME	= 	cub3D

FLAGS 	= 	-Wall -Werror -Wextra

CC 		= 	gcc

####################################-SOURCES-###################################

SRC		= 	main.c \
			
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
LIBFT_PATH	= Libft/
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
	$(CC) $(FLAGS) $(OBJS) -L./Libft -lft -L./minilibx-linux -lmlx -lXext -lX11 -lm -lz -o $(NAME)
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
