# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/01 22:22:03 by hkwon             #+#    #+#              #
#    Updated: 2021/03/03 00:19:53 by hkwon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

LIB_DIR = ./libft
OBJS_DIR = ./objs
SRCS_DIR = ./srcs
INCLUD_DIR = ./includes

SRCS = $(addprefix $(SRCS_DIR)/, \
		ft_printf.c\
		ft_init_list.c\
		ft_print_char.c\
		ft_print_str.c\
		ft_print_int.c\
		ft_print_un_int.c\
		ft_print_hex.c\
		ft_print_ptr.c\
		ft_print_per.c )

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