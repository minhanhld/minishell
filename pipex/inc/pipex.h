/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:07:22 by mle-duc           #+#    #+#             */
/*   Updated: 2023/10/13 09:39:30 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include "../libft/libft.h"

char	*find_path(char **envp);
char	*get_right_cmd_path(char **paths, char *cmd);
void	free_tab(char **tab);
void	print_err(char *str);
void	check_status(int status);
void	child1(char *argv[], char *envp[], int *pipefd);
void	child2(char *argv[], char *envp[], int *pipefd);

#endif