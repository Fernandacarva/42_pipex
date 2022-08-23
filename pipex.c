/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferncarv <ferncarv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:36:21 by ferncarv          #+#    #+#             */
/*   Updated: 2022/08/10 12:39:58 by ferncarv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    child(char **argv, char **envp, int *fd)
{
    int file;

    file = open(argv[1], O_RDONLY);
    if (file == -1)
    {
        error();
        exit(1);
    }
    dup2(fd[1], STOUT_FILENO);
    dup2(file, STDIN_FILENO);
    close(fd[0]);
    excve(argv[2], envp);
}

void    brother_process(char **argv, char **envp, int *fd)
{
    int int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
	if (outfile == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	excve(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int     fd[2];
	pid_t   pid1;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid1 = fork();
		if (pid1 == -1)
			error();
		if (pid1 == 0)
			child_process(argv, envp, fd);
		waitpid(pid1, NULL, 0);
		parent_process(argv, envp, fd);
	}
	else
	{
		ft_putstr_fd("Erro: Formato errado\n", 2);
		ft_putstr_fd("Formato correto: ./pipex infile cmd1 cmd2 outfile\n", 1);
	}
	return (0);
}

