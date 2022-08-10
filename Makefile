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
NAME		= 
SRCS		= 

OBJS		= $(SRCS:.c=.o)
RM			= rm -rf

.c.o:
			$(CC) $(CFLAGS) -I . -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C ./
			cp ./
			ar rcs $(NAME) $(OBJS)


clean:
			$(RM) $(OBJS)
			make clean -C ./

fclean:		clean
			$(RM) $(NAME)
			make fclean -C ./

re:			fclean all
			make re -C ./

.PHONY:		all clean fclean re
