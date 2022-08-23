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
NAME		= pipex 
SRCS		= pipex.c error.c

OBJS		= $(SRCS:.c=.o)
RM			= rm -rf

.c.o:
			$(CC) $(CFLAGS) -I . -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		    $(CC) $(OBJS) -o $(NAME)


clean:
        
            @make clean -C ./libft
		    @$(RM) $(OBJ)

fclean:		clean
			@make fclean -C ./libft
		    @$(RM) $(OBJ)

re:			fclean all

.PHONY:		all clean fclean re
