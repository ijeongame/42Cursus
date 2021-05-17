# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 01:15:50 by hkwon             #+#    #+#              #
#    Updated: 2021/05/18 04:41:44 by hkwon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
GNL = libgnl.a
LIBFT = libft.a
MLX = libmlx.a
MLX_LINUX = liblinux.a

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

LIB_DIR = ./lib/libft
GNL_DIR = ./lib/gnl
# MLX_DIR = ./lib/mlx
# MLX_MMS_DIR = ./lib/mlx_mms
MLX_LINUX_DIR = ./lib/mlx_linux
OBJS_DIR = ./objs
SRCS_DIR = ./srcs
INCLUDE_DIR = ./includes

SRCS_INIT_DIR = init
SRCS_CAST_DIR = cast
SRCS_KEY_DIR = key
SRCS_MAP_DIR = map

SRCS = $(addprefix $(SRCS_DIR)/, \
		$(addprefix $(SRCS_INIT_DIR)/, cub3d.c cub_init.c cub_texture.c cub_exit.c)\
		$(addprefix $(SRCS_CAST_DIR)/, cub_bmp.c cub_draw.c cub_floor.c\
		cub_sprite_sort.c cub_sprite_text.c cub_sprite.c cub_wall_text.c cub_wall.c)\
		$(addprefix $(SRCS_KEY_DIR)/, key_event.c key_look.c key_move.c key_play.c)\
		$(addprefix $(SRCS_MAP_DIR)/, map_render.c map_fc.c map_color.c\
		map_resolution.c map_valid.c map_vec.c map_parse.c map_check.c ))

OPENGL = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
MMS = -L$(MLX_BETA_DIR) -lmlxbeta -framework OpenGL -framework AppKit
LINUX = -L$(MLX_LINUX_DIR) -lmlx -lm -lXext -lX11 -lbsd

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

$(NAME) : $(LIBFT) $(GNL) $(MLX_LINUX)
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(GNL_DIR)/$(INCLUDE_DIR) -I$(LIB_DIR)/$(INCLUDE_DIR) -I$(MLX_LINUX_DIR) \
	-L./ -lgnl -L./ -lft $(LINUX) -o $(NAME) $(SRCS)

$(LIBFT) :
	@make -C $(LIB_DIR)
	@cp $(LIB_DIR)/$(LIBFT) .

$(GNL) :
	@make -C $(GNL_DIR)
	@cp $(GNL_DIR)/$(GNL) .

$(MLX) :
	@make -C $(MLX_DIR)
	@cp $(MLX_DIR)/$(MLX) .

$(MLX_BETA) :
	@make -C $(MLX_BETA_DIR)
	@cp $(MLX_BETA_DIR)/$(MLX_BETA) .

$(MLX_LINUX) :
	@make -C $(MLX_LINUX_DIR)
	@cp $(MLX_LINUX_DIR)/$(MLX_LINUX) .


$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(DEBUG) -I $(INCLUD_DIR) -I $(LIB_DIR) -c $< -o $@

clean :
	@rm -rf $(NAME)
	@rm -rf tmp_map
	# @make -C $(MLX_DIR) clean
	# @make -C $(MLX_BETA_DIR) clean
	@make -C $(MLX_LINUX_DIR) clean
	@make -C $(LIB_DIR) clean
	@make -C $(GNL_DIR) clean

fclean : clean
	@rm -rf $(MLX)
	@rm -rf $(MLX_BETA)
	@rm -rf $(MLX_LINUX)
	@rm -rf $(GNL)
	@rm -rf $(LIBFT)
	# @make -C $(MLX_DIR) clean
	# @make -C $(MLX_BETA_DIR) clean
	@make -C $(MLX_LINUX_DIR) clean
	@make -C $(LIB_DIR) fclean
	@make -C $(GNL_DIR) fclean

re : fclean all

.PHONY : all clean fclean re
