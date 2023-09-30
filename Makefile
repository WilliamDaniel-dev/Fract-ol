NAME = fractol
LIBFT = ./libft/libft.a
MINI_FLAGS = -lmlx -lX11 -lXext -lm
FLAGS = -Wall -Wextra -Werror -g3

SRCS = main.c\
	   hook.c\
	   start_window.c\
	   fractol.c

OBJS	= $(SRCS:%.c=%.o)

all: libft $(NAME)

libft:
	make -C ./libft

%.o:%.c
	cc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) 
	cc $(OBJS) $(LIBFT) $(MINI_FLAGS) -o $(NAME)


clean:
	rm -rf $(OBJS)
	make clean -C ./libft

fclean:	clean
	rm	-rf $(NAME)
	make fclean -C ./libft

re:	fclean all clean

.PHONY:	all clean fclean re libft


