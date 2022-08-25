/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferncarv <ferncarv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:26:21 by ferncarv          #+#    #+#             */
/*   Updated: 2022/08/25 14:59:56 by ferncarv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include <sys/wait.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>

char	*path_process(char *cmd, char **envp);
void	error(void);
int		child_process(char *argv[], char **envp, int *fd);
int		brother_process(char *argv[], char **envp, int *fd);
char	*test_access(char **path, char **cmd);
char	*get_path(char **envp, char **cmd);
char	**ft_trim(char **cmd);
char	**get_cmd(char *argv);
#endif
