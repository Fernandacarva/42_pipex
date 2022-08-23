/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferncarv <ferncarv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:26:21 by ferncarv          #+#    #+#             */
/*   Updated: 2022/08/10 11:58:31 by ferncarv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef PIPEX_H
# define PIPEX_H

# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/include/libft.h"
# include <sys/wait.h>
# include <stdlib.h>

char    *path_process(char *cmd, char **envp);
void	error(void);
#endif
