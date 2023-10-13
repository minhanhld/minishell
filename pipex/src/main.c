/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:07:02 by mle-duc           #+#    #+#             */
/*   Updated: 2023/10/13 09:51:46 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exe_cmd(char *cmd, char *envp[])
{
	char	**cmd_args;
	char	**path;
	char	*cmd_path;

	cmd_args = ft_split(cmd, ' ');
	if (cmd[0] == '/' && access(cmd_args[0], F_OK | X_OK) == 0)
		execve(cmd_args[0], cmd_args, envp);
	path = ft_split(find_path(envp), ':');
	cmd_path = get_right_cmd_path(path, cmd_args[0]);
	if (cmd_path == NULL)
	{
		ft_putstr_fd("Command not found\n", 2);
		free_tab(cmd_args);
		free_tab(path);
		exit(127);
	}
	execve(cmd_path, cmd_args, envp);
}

void	child1(char *argv[], char *envp[], int *pipefd)
{
	int	fd;

	fd = open(argv[1], O_RDONLY, 0777);
	if (fd < 0)
	{
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd(": Aucun fichier ou dossier de ce type\n", 2);
		exit(EXIT_FAILURE);
	}
	dup2(fd, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	exe_cmd(argv[2], envp);
}

void	child2(char *argv[], char *envp[], int *pipefd)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd < 0)
		exit(EXIT_FAILURE);
	dup2(fd, STDOUT_FILENO);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[1]);
	exe_cmd(argv[3], envp);
}

static void	create_pipes(int *pipefd, int nb_cmd)
{
	int	i;

	i = 0;
	while (i < nb_cmd - 1)
	{
		if (pipe(pipefd + 2 * i) < 0)
			exit(EXIT_FAILURE);
		i++;
	}
}

static void	close_pipes(int *pipefd, int nb_cmd)
{
	int	i;

	i = 0;
	while (i < 2 * (nb_cmd - 1))
		close(pipefd[i++]);
}

static void	redir(int pipein, int pipeout)
{
	dup2(pipein, 0);
	dup2(pipeout, 1);
}

void	child(int *pipefd, char *argv[], char *envp[], int i, int infile, int outfile, int nb_cmd)
{
	pid_t pid;

	pid = fork();
	if (pid > 0)
	{
		if (i == 0)
			redir(infile, pipefd[1]);
		else if (i == nb_cmd - 1)
			redir(pipefd[2 * i - 2], outfile);
		else
			redir(pipefd[2 * i - 2], pipefd[2 * i + 1]);
		close_pipes(pipefd, nb_cmd);
		exe_cmd(argv[2 + i], envp);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	int	infile;
	int	outfile;
	int	nb_cmd;
	int	*pipefd;
	int	i;

	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0000644);
	nb_cmd = argc - 3;
	pipefd = malloc(sizeof(int) * 2 * (nb_cmd - 1));
	if (!pipefd)
		return (EXIT_FAILURE);
	create_pipes(pipefd, nb_cmd);
	i = 0;
	while (i < nb_cmd)
		child(pipefd, argv, envp, i++, infile, outfile, nb_cmd);
	close_pipes(pipefd, nb_cmd);
	waitpid(-1, NULL, 0);
	return (0);
}
