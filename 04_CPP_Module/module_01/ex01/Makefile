# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 14:10:03 by hkwon             #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2021/11/24 20:41:25 by hkwon            ###   ########.fr        #
=======
#    Updated: 2021/12/28 19:15:16 by hkwon            ###   ########.fr        #
>>>>>>> 64486e2be31f95f0ddcc8b6a18b59d1662c43400
#                                                                              #
# **************************************************************************** #

NAME = zombieHorde
CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98
#CFLAGS = -g3 -fsanitize=address

OBJS_DIR = ./objs
SRCS =	./main.cpp \
		./Zombie.cpp \
		./ZombieHorde.cpp

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.cpp=.o)))
RM = rm -f

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS_DIR) :
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o : %.cpp | $(OBJS_DIR)
	$(CC) $(CFLAGS) -o $@ -c $^

clean :
	@$(RM) -r $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)

re : fclean all
