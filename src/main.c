/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 08:42:25 by mle-duc           #+#    #+#             */
/*   Updated: 2023/10/09 16:57:54 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	if (argc == 2)
	{
		char	**split = ft_split(argv[1], ' ');
		pwd();
		//ft_exit(split);
		//ft_echo(split);
		ft_env(envp);
	}
	return (0);
}
