/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:07:02 by mle-duc           #+#    #+#             */
/*   Updated: 2023/10/13 20:53:41 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exe_cmd(char **cmd_args, char *envp[])
{
	char	**path;
	char	*cmd_path;

	if (cmd_args[0][0] == '/' && access(cmd_args[0], F_OK | X_OK) == 0)
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

static void	init_pars(t_pars *pars, char *cmd, int outfile, int infile)
{
	pars->cmd = ft_split(cmd, ' ');
	pars->infile = infile;
	pars->outfile = outfile;
	pars->append = 0;
	pars->delimiter = NULL;
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pars	*pars;
	t_pars	*pars2;
	t_pars	*pars3;

	int fd = 0;
	if (argc > 1)
		fd = open(argv[1], O_RDONLY);
	pars = malloc(sizeof(t_pars));
	pars2 = malloc(sizeof(t_pars));
	pars3 = malloc(sizeof(t_pars));

	init_pars(pars, "tac", 0, fd);
	init_pars(pars2, "cat", 0, 0);
	init_pars(pars3, "tac", 0 , 0);

	pars->next = pars2;
	pars2->next = NULL;
	//pars2->next = pars3;
	//pars3->next = NULL;

	executor(pars, envp);
	close(fd);
	free_tab(pars->cmd);
	free_tab(pars2->cmd);
	free_tab(pars3->cmd);
	free(pars);
	free(pars2);
	free(pars3);
	return (0);
}

