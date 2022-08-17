/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Makefile                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferncarv <ferncarv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:36:21 by ferncarv          #+#    #+#             */
/*   Updated: 2022/07/10 02:47:04 by ferncarv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
NAME		= pipex.a 
SRCS		= pipex.c

OBJS		= $(SRCS:.c=.o)
RM			= rm -rf

.c.o:
			$(CC) $(CFLAGS) -I . -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		    $(CC) $(OBJS) -o $(NAME)


clean:
			$(RM) $(OBJS)
			make clean $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			make fclean $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
