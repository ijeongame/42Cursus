# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 01:15:50 by hkwon             #+#    #+#              #
#    Updated: 2021/05/22 15:47:38 by hkwon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D


GNL = libgnl.a
LIBFT = libft.a
MLX = libmlx.a
MLX_MMS = libmlxmms.dylib

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -f

LIB_DIR = ./lib/libft
GNL_DIR = ./lib/gnl
MLX_DIR = ./lib/mlx
MLX_MMS_DIR = ./lib/mlx_mms
SRCS_DIR = ./srcs
INCLUDE_DIR = ./includes

SRCS_INIT_DIR = init
SRCS_CAST_DIR = cast
SRCS_KEY_DIR = key
SRCS_MAP_DIR = map
SRCS_BONUS_DIR = bonus

SRCS = $(addprefix $(SRCS_DIR)/, \
		$(addprefix $(SRCS_INIT_DIR)/, cub3d.c cub_init.c cub_texture.c cub_exit.c)\
		$(addprefix $(SRCS_CAST_DIR)/, cub_bmp.c cub_draw.c cub_floor.c\
		cub_sprite_sort.c cub_sprite_text.c cub_sprite.c cub_wall_text.c cub_wall.c)\
		$(addprefix $(SRCS_KEY_DIR)/, key_event.c key_look.c key_move.c key_play.c)\
		$(addprefix $(SRCS_MAP_DIR)/, map_line_free.c map_render.c map_fc.c	map_resolution.c map_valid.c map_vec.c map_parse.c map_check.c)\
		$(addprefix $(SRCS_BONUS_DIR)/, cub_sound.c))

OPENGL = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
MMS = -L$(MLX_MMS_DIR) -lmlxmms -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(LIBFT) $(GNL) $(MLX) $(MLX_MMS) $(SRCS)
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(GNL_DIR)/$(INCLUDE_DIR) -I$(LIB_DIR)/$(INCLUDE_DIR) -I$(MLX_DIR) \
	-L./ -lgnl -L./ -lft $(OPENGL) $(MMS) -o $(NAME) $(SRCS)

$(LIBFT) :
	@make -C $(LIB_DIR)
	@cp $(LIB_DIR)/$(LIBFT) .

$(GNL) :
	@make -C $(GNL_DIR)
	@cp $(GNL_DIR)/$(GNL) .

$(MLX) :
	@make -C $(MLX_DIR)
	@cp $(MLX_DIR)/$(MLX) .

$(MLX_MMS) :
	@make -C $(MLX_MMS_DIR)
	@cp $(MLX_MMS_DIR)/$(MLX_MMS) .

clean :
	@rm -rf tmp
	@make -C $(MLX_DIR) clean
	@make -C $(MLX_MMS_DIR) clean
	@make -C $(LIB_DIR) clean
	@make -C $(GNL_DIR) clean

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(MLX)
	@rm -rf $(MLX_MMS)
	@rm -rf $(GNL)
	@rm -rf $(LIBFT)
	@make -C $(LIB_DIR) fclean
	@make -C $(GNL_DIR) fclean

re : fclean all

bonus : all

.PHONY : all clean fclean re
