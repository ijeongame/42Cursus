# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 21:29:08 by hkwon             #+#    #+#              #
#    Updated: 2021/07/04 20:00:46 by hkwon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PHILO = PHILO
PHILO_BONUS = PHILO_BONUS
NAME = $(PHILO)
BONUS = $(PHILO_BONUS)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -f

INCLUDE_DIR = ./includes
SRCS_DIR = ./srcs
UTILS_DIR = ./utils

SRCS = $(addprefix $(SRCS_DIR)/, \
		main.c print.c))

UTILS = $(addprefix $(UTILS_DIR)/, \
		ft_atoi.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c)

all : $(NAME)

$(PHILO) : $(SRCS)
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) \
	-lft -o $(PHILO) $(SRCS) $(UTILS)

$(PHILO_BONUS) : $(SRCS)
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR)\
	-lft -o $(PHILO_BONUS) $(UTILS)

bonus : $(BONUS)

clean :
	@make -C $(LIB_DIR) clean

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)
	@make -C $(LIB_DIR) fclean

re : fclean all

.PHONY : all clean fclean re
