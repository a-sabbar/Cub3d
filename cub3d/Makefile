# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youchenn <youchenn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 11:06:58 by asabbar           #+#    #+#              #
#    Updated: 2022/10/11 20:07:27 by youchenn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

NAME_BONUS = cub3D_bonus

FLAGS = -Wall -Wextra -Werror

INCLUDES = cub3d.h
		
SRC =	main.c										\
		function_utils/ft_atoi.c					\
		function_utils/ft_split.c					\
		function_utils/ft_strtrim.c				\
		function_utils/ft_substr.c					\
		function_utils/ft_utils.c 					\
		function_utils/get_next_line.c				\
		function_utils/get_next_line_utils.c		\
		parser/ft_colors.c							\
		parser/ft_textures.c						\
		parser/ft_check_map.c						\
		key_hook.c	handel_map_2.c					\
		get_textures_data.c							\
		render.c									\
		our_put_pixel.c	drawing_field_of_view.c  \
		render_wall.c 	check_walls.c	parser/check_map_utils.c  parser/parse_map.c	\
		trait_map.c		raycasting_1.c	 raycasting_2.c\

SRC_BNS =	main_bonus.c										\
			function_utils/ft_atoi.c					\
			function_utils/ft_utils.c 					\
			function_utils/ft_split.c					\
			function_utils/ft_strtrim.c				\
			function_utils/ft_substr.c					\
			function_utils/get_next_line.c				\
			function_utils/get_next_line_utils.c		\
			parser/ft_colors.c							\
			parser/ft_textures.c						\
			parser/ft_check_map.c						\
			mouse_management.c							\
			key_hook.c	handel_map_2.c	drawing_map.c							\
			get_textures_data.c							\
			render.c									\
			our_put_pixel.c	drawing_field_of_view_bonus.c  \
			render_wall.c 	check_walls.c	parser/check_map_utils.c  parser/parse_map.c	\
			trait_map.c		raycasting_1.c	 raycasting_2.c\
	

OBJECTS = $(SRC:.c=.o)


OBJECTSB = $(SRC_BNS:.c=.o)

all: $(NAME)
	@echo "------------------Cub 3D-----------------\n\n\n"

$(NAME): $(OBJECTS)
	@$(CC) $(FLAGS) -lmlx -lm -framework OpenGL -framework AppKit $(OBJECTS)  -o $(NAME)

%.o : %.c $(INCLUDES) $(INCLUDES2)
	$(CC) $(FLAGS) -Imlx -Ofast  -c $< -o $@

bonus: $(OBJECTSB)
	@$(CC) $(FLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJECTSB)  -o $(NAME_BONUS)
clean:
	@rm -rf $(OBJECTS) $(OBJECTSB)  

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS) 

re: fclean all