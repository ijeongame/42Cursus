# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/04 03:12:03 by kwonhyukbae       #+#    #+#              #
#    Updated: 2021/10/11 23:14:37 by hkwon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIBFT = libft.a

CC = gcc
# CFLAGS = -Wall -Wextra -Werror
CFLAGS = -g3 -fsanitize=address

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

SRCS_INIT_DIR = $(SRCS_DIR)/init
SRCS_INIT = $(addprefix $(SRCS_INIT_DIR)/, \
		init_shell.c\
)

SRCS_PARSE_DIR = $(SRCS_DIR)/parsing
SRCS_PARSE = $(addprefix $(SRCS_PARSE_DIR)/, \
		parse_start.c\
		parse_line.c\
		parse_token.c\
		parse_token_arr.c\
		parse_token_list.c\
)

SRCS_MAIN = $(addprefix $(SRCS_DIR)/, \
		main.c minishell.c)

SRCS = \
	$(SRCS_MAIN) \
	$(SRCS_INIT) \
	$(SRCS_PARSE) \
	# $(SRCS_BUILTIN)


# OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

vpath %.c \
	$(SRCS_DIR) \
	$(SRCS_INIT_DIR) \
	$(SRCS_PARSE_DIR) \

all : $(NAME)

$(NAME) : $(LIBFT)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -I $(LIB_DIR)/$(INCLUDE_DIR) \
	-L ./$(LIB_DIR) -lreadline -L/usr/local/opt/readline/lib -I/usr/local/opt/readline/include \
	-lft -o $(NAME) $(SRCS)

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
