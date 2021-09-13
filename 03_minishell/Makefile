# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/04 03:12:03 by kwonhyukbae       #+#    #+#              #
#    Updated: 2021/09/13 16:20:15 by hkwon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIBFT = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -g3 -fsanitize=address

AR = ar rc
RM = rm -f

INCLUDE_DIR = ./includes
SRCS_DIR = ./srcs
# OBJS_DIR = ./objs
LIB_DIR = ./libft

SRCS_BUILTIN_DIR = $(SRCS_DIR)/builtin_func
SRCS_BUILTIN = $(addprefix $(SRCS_BUILTIN_DIR)/, \
		ft_echo.c \
		ft_cd.c \
		ft_pwd.c \
		ft_export.c \
		ft_unset.c \
		ft_env.c \
		ft_exit.c \
)

SRCS_MAIN = $(addprefix $(SRCS_DIR)/, \
		main.c minishell.c execute.c builtin.c setenv.c)

SRCS =  $(SRCS_MAIN) \
		# $(SRCS_BUILTIN)
		

# OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

vpath %.c \
	$(SRCS_DIR) \
	# $(SRCS_BUILTIN_DIR)

all : $(NAME)

$(NAME) : $(LIBFT)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -I $(LIB_DIR)/$(INCLUDE_DIR) \
	-L ./$(LIB_DIR) -lft -o $(NAME) $(SRCS)

# $(OBJS_DIR) :
# 	@mkdir -p $(OBJS_DIR)

# $(OBJS_DIR)/%.o : %.c | $(OBJS_DIR) 
# 	$(CC) $(CFLAGS) -o $@ -I$(INCLUDE_DIR) -c $^

$(LIBFT) :
	@make -C $(LIB_DIR)
	@cp $(LIB_DIR)/$(LIBFT) .
	
clean :
	@$(RM) -r $(OBJS_DIR)
	@make -C $(LIB_DIR) clean

fclean : clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@make -C $(LIB_DIR) fclean
	
re : fclean all

.PHONY : all clean fclean re
