# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 21:29:08 by hkwon             #+#    #+#              #
#    Updated: 2021/09/26 15:51:06 by hkwon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -f

INCLUDE_DIR = ./includes
OBJS_DIR = ./objs
SRCS_DIR = ./srcs

SRCS = $(addprefix $(SRCS_DIR)/, \
		ft_pipe.c ft_pipe_process.c ft_pipe_execute.c \
		ft_split.c ft_strjoin.c ft_strncmp.c)

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))
vpath %.c \
	$(SRCS_DIR) \

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -o $@ -I$(INCLUDE_DIR) -c $^

clean :
	@$(RM) -r $(OBJS_DIR)
	
fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
