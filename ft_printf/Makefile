NAME = libftprintf.a
LIBFT = libft.a

AR = ar
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
		ft_printf.c ft_parse_start.c ft_parse_format.c \
		ft_print_int.c ft_print_char.c \ ft_print_str.c \
		ft_print_per.c ft_store_res.c \
		ft_check_extend.c)

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

bonus : all

$(NAME) : $(OBJS)
	@make -C $(LIB_DIR)
	@cp $(LIB_DIR)/$(LIBFT)
	@mv $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJS)


$(OBJS_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(DEBUG) -I$(INCLUD_LIBFT) -I $(LIB_DIR) -c $< -o $@ 

clean :
	@make -C $(LIB_DIR) clean
	$(RM) -rd $(OBJS_DIR)

fclean : clean
	@$(RM) $(LIB_DIR)
	@$(RM) $(NAME)

test :  

re : fclean all

.PHONY : all clean fclean re