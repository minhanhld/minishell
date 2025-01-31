/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:03:15 by mle-duc           #+#    #+#             */
/*   Updated: 2022/11/07 14:03:15 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while (s1[i] && i < n)
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	if (i == n)
		i--;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
