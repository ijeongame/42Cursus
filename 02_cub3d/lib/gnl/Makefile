# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/28 01:44:40 by hkwon             #+#    #+#              #
#    Updated: 2021/05/20 21:02:05 by hkwon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a

AR = ar rc
RM = rm -f

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJS_DIR = ./objs
SRCS_DIR = ./srcs
INCLUDE_DIR = ./includes

SRCS = $(addprefix $(SRCS_DIR)/, get_next_line.c get_next_line_utils.c)

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

$(NAME) : $(OBJS)
	@$(AR) $@ $^

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

clean :
	@$(RM) -rd $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)

re : fclean all
.PHONY : all clean fclean re

