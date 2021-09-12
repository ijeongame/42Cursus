# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 21:29:08 by hkwon             #+#    #+#              #
#    Updated: 2021/09/12 17:11:15 by hkwon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = pipex

# CC = gcc
# CFLAGS = -Wall -Wextra -Werror

# AR = ar rcs
# RM = rm -f

# INCLUDE_DIR = ./includes
# SRCS_MAN_DIR = ./srcs
# SRCS_BONUS_DIR = ./bonus
# OBJS_MAN_DIR = ./objs
# OBJS_BONUS_DIR = ./objs_b

# SRCS_MAN = $(addprefix $(SRCS_MAN_DIR)/, \
# 		ft_pipe.c ft_pipe_process.c ft_pipe_execute.c \
# 		ft_split.c ft_strjoin.c ft_strncmp.c)

# SRCS_BONUS = $(addprefix $(SRCS_BONUS_DIR)/, \
# 		ft_pipe_bonus.c ft_pipe_process_bonus.c ft_pipe_execute_bonus.c \
# 		ft_split_bonus.c ft_strjoin_bonus.c ft_strncmp_bonus.c)

# ifeq ($(CHECK_BONUS),1)
# 	OBJS = $(addprefix $(OBJS_BONUS_DIR)/, $(notdir $(SRCS_BONUS:.c=.o)))
# 	OBJS_DIR = OBJS_BONUS_DIR
# else
# 	OBJS = $(addprefix $(OBJS_MAN_DIR)/, $(notdir $(SRCS_MAN:.c=.o)))
# 	OBJS_DIR = OBJS_MAN_DIR
# endif

# # vpath %.c \
# # 	$(SRCS_DIR)

# all : $(NAME)

# $(NAME) : $(OBJS)
# 	$(CC) $(CFLAGS) -o $@ $^

# $(OBJS_DIR) :
# 	@mkdir -p $(OBJS_DIR)

# $(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
# 	$(CC) $(CFLAGS) -o $@ -I$(INCLUDE_DIR) -c $^

# bonus : make CHECK_BONUS=1 all

# clean :
# 	@$(RM) -r $(OBJS_DIR)

# fclean : clean
# 	@$(RM) $(NAME)

# re : fclean all

# .PHONY : all bonus clean fclean re

NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -f

INCLUDE_DIR = ./includes
OBJS_DIR = ./objs
SRCS_DIR = ./srcs
SRCS_BONUS_DIR = ./bonus
OBJS_BONUS_DIR = ./objs_b

SRCS = $(addprefix $(SRCS_DIR)/, \
		ft_pipe.c ft_pipe_process.c ft_pipe_execute.c \
		ft_split.c ft_strjoin.c ft_strncmp.c)

SRCS_BONUS = $(addprefix $(SRCS_BONUS_DIR)/, \
		ft_pipe.c ft_pipe_process.c ft_pipe_execute.c \
		ft_split.c ft_strjoin.c ft_strncmp.c)

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))
OBJS_BONUS = $(addprefix $(OBJS_BONUS_DIR)/, $(notdir $(SRCS_BONUS:.c=.o)))

vpath %.c \
	$(SRCS_DIR) \
	$(SRCS_BONUS_DIR)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -o $@ -I$(INCLUDE_DIR) -c $^

bonus : $(OBJS_BONUS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

$(OBJS_BONUS_DIR) :
	@mkdir -p $(OBJS_BONUS_DIR)

$(OBJS_BONUS_DIR)/%.o : %.c | $(OBJS_BONUS_DIR)
	$(CC) $(CFLAGS) -o $@ -I$(INCLUDE_DIR) -c $^

clean :
	@$(RM) -r $(OBJS_DIR)
	@$(RM) -r $(OBJS_BONUS_DIR)
	
fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
