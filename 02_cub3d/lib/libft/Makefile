# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/28 01:44:43 by hkwon             #+#    #+#              #
#    Updated: 2021/04/28 02:10:52 by hkwon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

AR = ar rc
RM = rm -f

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJS_DIR = ./objs
SRCS_DIR = ./srcs
INCLUD_DIR = ./includes

SRCS = $(addprefix $(SRCS_DIR)/, \
			ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c\
			ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c\
			ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c\
			ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putchar.c ft_putstr.c\
			ft_lltoa.c ft_convert_base.c)

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
