# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/28 01:44:43 by hkwon             #+#    #+#              #
#    Updated: 2021/06/11 23:09:41 by hkwon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

AR = ar rc
RM = rm -f

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJS_DIR = ./objs
SRCS_DIR = ./srcs
INCLUDE_DIR = ./includes

SRCS_CHECK_DIR = $(SRCS_DIR)/check
SRCS_CHECK = $(addprefix $(SRCS_CHECK_DIR)/, \
			ft_isalpha.c\
			ft_isdigit.c\
			ft_isalnum.c\
			ft_isascii.c\
			ft_isprint.c\
			ft_toupper.c\
			ft_tolower.c\
)

SRCS_LIST_DIR = $(SRCS_DIR)/list
SRCS_LIST = $(addprefix $(SRCS_LIST_DIR)/, \
			ft_lstadd_back.c\
			ft_lstadd_front.c\
			ft_lstclear.c\
			ft_lstdelone.c\
			ft_lstiter.c\
			ft_lstlast.c\
			ft_lstmap.c\
			ft_lstnew.c\
			ft_lstsize.c\
)

SRCS_NUM_DIR = $(SRCS_DIR)/num
SRCS_NUM = $(addprefix $(SRCS_NUM_DIR)/, \
			ft_lltoa.c\
			ft_convert_base.c\
			ft_count.c\
			ft_atoi.c\
			ft_itoa.c\
			ft_atol.c\
)

SRCS_MEMORY_DIR = $(SRCS_DIR)/memory
SRCS_MEMORY = $(addprefix $(SRCS_MEMORY_DIR)/, \
			ft_memset.c\
			ft_bzero.c\
			ft_memcpy.c\
			ft_memccpy.c\
			ft_memmove.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_calloc.c\
)

SRCS_PRINT_DIR = $(SRCS_DIR)/print
SRCS_PRINT = $(addprefix $(SRCS_PRINT_DIR)/, \
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_putchar.c\
			ft_putstr.c\
)

SRCS_STRING_DIR = $(SRCS_DIR)/string
SRCS_STRING = $(addprefix $(SRCS_STRING_DIR)/, \
			ft_strlen.c\
			ft_strlcpy.c\
			ft_strlcat.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_strnstr.c\
			ft_strcmp.c\
			ft_strncmp.c\
			ft_strdup.c\
			ft_strndup.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_strtrim.c\
			ft_split.c\
			ft_strmapi.c\
)

SRCS = \
		$(SRCS_CHECK)\
		$(SRCS_LIST)\
		$(SRCS_MEMORY)\
		$(SRCS_NUM)\
		$(SRCS_PRINT)\
		$(SRCS_STRING)

vpath %.c \
		$(SRCS_DIR)\
		$(SRCS_CHECK_DIR)\
		$(SRCS_LIST_DIR)\
		$(SRCS_MEMORY_DIR)\
		$(SRCS_NUM_DIR)\
		$(SRCS_PRINT_DIR)\
		$(SRCS_STRING_DIR)

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

$(NAME) : $(OBJS)
	@$(AR) $@ $^

$(OBJS_DIR)/%.o : %.c $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

clean :
	@$(RM) -rd $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
