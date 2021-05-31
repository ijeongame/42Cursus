# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 21:29:08 by hkwon             #+#    #+#              #
#    Updated: 2021/06/01 06:21:39 by hkwon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
CHECKER = checker
NAME = $(PUSH_SWAP) $(CHECKER)

LIBFT = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -g3 -fsanitize=address

AR = ar rcs
RM = rm -f

LIB_DIR = ./libft
SRCS_DIR = ./srcs
INCLUDE_DIR = ./includes

SRCS_INIT_DIR = init
SRCS_OP_DIR = op
SRCS_UTILS_DIR = utils
SRCS_ALGO_DIR = algo
SRCS_CHECK_DIR = checker

SRCS_PUSH = $(addprefix $(SRCS_DIR)/, \
		$(addprefix $(SRCS_INIT_DIR)/, main.c))

SRCS_COMMON = $(addprefix $(SRCS_DIR)/, \
		$(addprefix $(SRCS_OP_DIR)/, op_pa.c op_pb.c op_ra.c op_rb.c op_rr.c op_rra.c op_rrb.c op_rrr.c op_sa.c op_sb.c op_ss.c)\
		$(addprefix $(SRCS_ALGO_DIR)/, algo_init.c algo_less.c algo_handle_a.c algo_handle_b.c algo_a_to_b.c algo_b_to_a.c)\
		$(addprefix $(SRCS_UTILS_DIR)/, util_start.c util_lst.c util_parse.c util_algo.c util_sort.c util_exec.c util_escape.c util_free.c))

SRCS_CHECK = $(addprefix $(SRCS_DIR)/, \
		$(addprefix $(SRCS_CHECK_DIR)/, main.c check_init.c check_run.c))

all : $(NAME)

$(PUSH_SWAP) : $(LIBFT) $(SRCS_PUSH)
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIB_DIR)/$(INCLUDE_DIR) \
	-L ./$(LIB_DIR) -lft -o $(PUSH_SWAP) $(SRCS_PUSH) $(SRCS_COMMON)

$(CHECKER) : $(LIBFT) $(SRCS_CHECK)
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIB_DIR)/$(INCLUDE_DIR) \
	-L ./$(LIB_DIR) -lft -o $(CHECKER) $(SRCS_CHECK) $(SRCS_COMMON)

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
