# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/28 01:44:40 by hkwon             #+#    #+#              #
#    Updated: 2021/04/28 02:10:59 by hkwon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a

AR = ar rc
RM = rm -f

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJS_DIR = ./objs
SRCS_DIR = ./srcs
INCLUD_DIR = ./includes

SRCS = $(addprefix $(SRCS_DIR)/, get_next_line.c get_next_line_utils.c)

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C $(LIB_DIR)
	@cp $(LIB_DIR)/$(LIBFT) .
	@mv $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJS)

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(DEBUG) -I $(INCLUD_DIR) -I $(LIB_DIR) -c $< -o $@

clean :
	@make -C $(LIB_DIR) clean
	$(RM) -rd $(OBJS_DIR)

fclean : clean
	@$(RM) $(LIB_DIR)/$(LIBFT)
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
