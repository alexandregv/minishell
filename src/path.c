/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 00:35:02 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/28 17:06:37 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_parse_path(char **env)
{
	char	**parsed;
	char	*var;

	if (!(var = ft_getenv(env, "PATH")))
		return (ft_split("", 0));
	parsed = ft_split(var, ':');
	return (parsed);
}

char	*from_path(char **path, char *file)
{
	char	*fullpath;
	int		in;

	in = 0;
	while (*path)
	{
		fullpath = ft_strjoin3(*path, "/", file);
		if (access(fullpath, F_OK) == 0)
			return (fullpath);
		++path;
		++in;
		free(fullpath);
	}
	return (NULL);
}
