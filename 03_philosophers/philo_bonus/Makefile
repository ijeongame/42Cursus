# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwonhyukbae <kwonhyukbae@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/08 19:59:27 by hkwon             #+#    #+#              #
#    Updated: 2021/07/31 00:44:45 by kwonhyukbae      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC = gcc
# CFLAGS = -Wall -Wextra -Werror
CFLAGS = -g3 -fsanitize=address

AR = ar rcs
RM = rm -f

INCLUDE_DIR = ./includes
OBJS_DIR = ./objs
SRCS_DIR = ./srcs

SRCS = $(addprefix $(SRCS_DIR)/, \
		main.c init.c semaphore.c routine.c monitor.c print.c name.c util.c)

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

vpath %.c \
	$(SRCS_DIR)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -I$(INCLUDE_DIR) -c $^

clean :
	@$(RM) -r $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
