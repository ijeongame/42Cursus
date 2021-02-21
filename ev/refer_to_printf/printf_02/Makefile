SRCS	=   ./src/apply_format.c \
            ./src/format_checker.c \
            ./src/ft_atoi.c \
            ./src/ft_itoa.c \
            ./src/ft_strchr.c \
            ./src/ft_strdup.c \
            ./src/ft_strjoin.c \
            ./src/ft_strlcat.c \
            ./src/ft_strlcpy.c \
            ./src/ft_strlen.c \
            ./src/ft_strncmp.c \
            ./src/ft_substr.c \
            ./src/common_func.c \
            ./src/get_int_value.c \
            ./src/get_uint_value.c \
            ./src/get_char_value.c \
            ./src/get_string_value.c \
            ./src/get_pointer_value.c \
            ./src/get_percent_value.c \
            ./src/get_value_by_type.c \
			ft_printf.c \

OBJS	= $(SRCS:.c=.o)
CC	= GCC
CFLAGS	= -Wall -Wextra -Werror
NAME	= libftprintf.a
RM	= rm -f
all:		$(NAME)
$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)
clean:
			$(RM) $(OBJS)
fclean:		clean
			$(RM) $(NAME)
re:			fclean $(NAME)
.PHONY:	all clean fclean re
