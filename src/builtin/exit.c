/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:27:00 by mle-duc           #+#    #+#             */
/*   Updated: 2023/10/06 18:54:06 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_arg_valid(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args && args[i])
	{
		if (ft_is 
int	exit(char **args)
{
	int	exit_code;

	if (ft_strncmp(args[0], "exit", ft_strlen(args[0])) != 0)
		return (EXIT_FAILURE);
	if (args[1])
		exit_code = ft_atoi(args[1]);
	else
		exit_code = get_err_code();
	if
