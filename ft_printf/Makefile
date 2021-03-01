NAME = libftprintf.a
LIBFT = libft.a

AR = ar r
ARFLAGS = crs

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm
RMFLAGS = -f

LIB_DIR = ./libft
OBJS_DIR = ./objs
SRCS_DIR = ./srcs
INCLUD_DIR = ./includes

SRCS = $(addprefix $(SRCS_DIR)/, \
		ft_printf.c\
		ft_init_list.c\
		ft_print_char.c\
		ft_print_int.c\
		ft_print_un_int.c\
		ft_print_hex.c\
		ft_print_ptr.c )

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

bonus : all

$(NAME) : $(OBJS)
	@make -C $(LIB_DIR)
	@cp $(LIB_DIR)/$(LIBFT) .
	@mv $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJS)

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(DEBUG) -I$(INCLUD_LIBFT) -I $(LIB_DIR) -c $< -o $@ 

clean :
	@make -C $(LIB_DIR) clean
	$(RM) -rd $(OBJS_DIR)

fclean : clean
	@$(RM) $(LIB_DIR)
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re