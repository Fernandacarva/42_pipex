NAME	= pipex

SRCS	= 	pipex_utils.c \
			pipex.c

OBJS	=  $(SRCS:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			cc $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			make -C ./libft
			cc $(SRCS) ./libft/libft.a -o pipex

all:		$(NAME)

clean:
			rm -f $(OBJS)
			make clean -C ./libft

fclean:		clean
			rm -f $(NAME)
			make fclean -C ./libft

re:			fclean all

.PHONY:		all clean fclean re
