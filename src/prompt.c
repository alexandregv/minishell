/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 00:35:23 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/28 00:35:25 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	prompt(char **env)
{
	char	buff[4096 + 1];
	char	*buffptr;
	char	*home;

	if (isatty(0) && isatty(1))
	{
		getcwd(buff, 4096);
		home = ft_getenv(env, "HOME");
		if (home != NULL)
		{
			if (!ft_strncmp(buff, home, ft_strlen(home)))
			{
				buffptr = buff + ft_strlen(home);
				ft_putchar('~');
			}
			else
				buffptr = buff;
		}
		else
			buffptr = buff;
		ft_putstr(buffptr);
		ft_putstr(" \033[33m$>\033[39m ");
	}
	return (1);
}
