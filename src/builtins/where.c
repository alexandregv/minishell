/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 00:35:44 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/28 00:35:44 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	in_path(char **path, char *bin)
{
	char	*fullpath;
	int		found;

	found = 0;
	while (*path && !found)
	{
		fullpath = ft_strjoin3(*path, "/", bin);
		if (access(fullpath, F_OK) == 0)
		{
			ft_putendl(fullpath);
			found = 1;
		}
		++path;
		free(fullpath);
	}
	return (found);
}

int			where_builtin(char **path, char **argv)
{
	int		found;

	if (!argv[1])
		return (0);
	found = in_path(path, argv[1]);
	if (!ft_strcmp(argv[1], "echo") || !ft_strcmp(argv[1], "cd")
			|| !ft_strcmp(argv[1], "setenv") || !ft_strcmp(argv[1], "unsetenv")
			|| !ft_strcmp(argv[1], "env") || !ft_strcmp(argv[1], "exit")
			|| !ft_strcmp(argv[1], "where"))
	{
		ft_putstr(argv[1]);
		ft_putendl(": shell built-in command");
		found = 1;
	}
	if (!found)
	{
		ft_putstr(argv[1]);
		ft_putendl(" not found");
	}
	return (0);
}
