/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferncarv <ferncarv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:56:53 by ferncarv          #+#    #+#             */
/*   Updated: 2022/08/18 11:01:56 by ferncarv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.c"

void    error(void)
{
    ft_putstr_fd("Error!", 2);
    exit(EXIT_FAILURE);
}

char    *path_process(char *cmd, char **envp)
{
    int i;
    char    *in_path;
    char    *path;
    char    **paths;

    i = 0;
    while (ft_strnstr(envp[i], "PATH", 4) == 0)
        i++;
    paths = ft_split(envvp[i] + 5, ':');
    i = -1;
    while (paths[++i])
    {
		init_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(init_path, cmd);
		free(init_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
	}
    i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (cmd);
}

