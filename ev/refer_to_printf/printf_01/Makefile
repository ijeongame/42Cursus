NAME	=	libftprintf.a

OBJS	=	ft_printf.o \
			ft_printf_utils.o \
			ft_print_text.o \
			ft_print_nbr.o \

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
LIBC	=	ar -rcs

$(NAME): $(OBJS)
	make all -C ./libft
	cp libft/libft.a ./$(NAME)
	$(LIBC) $(NAME) $(OBJS)

all: $(NAME)

clean:
	make clean -C ./libft
	rm -f $(OBJS)

fclean:
	make fclean -C ./libft
	rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
