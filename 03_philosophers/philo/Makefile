# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 21:29:08 by hkwon             #+#    #+#              #
#    Updated: 2021/07/06 16:57:20 by hkwon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -f

INCLUDE_DIR = ./includes
OBJS_DIR = ./objs
SRCS_DIR = ./srcs
UTILS_DIR = ./utils

SRCS = $(addprefix $(SRCS_DIR)/, \
		main.c init.c philo.c))

UTILS = $(addprefix $(UTILS_DIR)/, \
		ft_atoi.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c)

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -I$(INCLUDE_DIR) -c $^

clean :
	@$(RM) -r (OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
