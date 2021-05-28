# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 21:29:08 by hkwon             #+#    #+#              #
#    Updated: 2021/05/28 18:14:44 by hkwon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

LIBFT = libft.a

CC = gcc
# CFLAGS = -Wall -Wextra -Werror
CFLAGS = -g3 -fsanitize=address


AR = ar rcs
RM = rm -f

LIB_DIR = ./libft
SRCS_DIR = ./srcs
INCLUDE_DIR = ./includes

SRCS_INIT_DIR = init
SRCS_OP_DIR = op
SRCS_UTILS_DIR = utils
SRCS_ALGO_DIR = algo

SRCS = $(addprefix $(SRCS_DIR)/, \
		$(addprefix $(SRCS_INIT_DIR)/, main.c ps_parsing.c)\
		$(addprefix $(SRCS_OP_DIR)/, op_pa.c op_pb.c op_ra.c op_rb.c op_rr.c op_rra.c op_rrb.c op_rrr.c op_sa.c op_sb.c op_ss.c)\
		$(addprefix $(SRCS_ALGO_DIR)/, algo_init.c)\
		$(addprefix $(SRCS_UTILS_DIR)/, util_lst.c util_parse.c util_algo.c util_free.c))

all : $(NAME)

$(NAME) : $(LIBFT) $(SRCS)
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIB_DIR)/$(INCLUDE_DIR) \
	-L ./$(LIB_DIR) -lft -o $(NAME) $(SRCS)

$(LIBFT) :
	@make -C $(LIB_DIR)
	@cp $(LIB_DIR)/$(LIBFT) .

clean :
	@make -C $(LIB_DIR) clean

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)
	@make -C $(LIB_DIR) fclean

re : fclean all

.PHONY : all clean fclean re
