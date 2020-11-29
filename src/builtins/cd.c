/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 08:55:04 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/29 16:37:40 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_directory(char **argv, char ***env)
{
	char	*str;
	char	*var;

	if ((str = ft_join_table(argv + 1, " ")) == NULL)
		exit(1);
	if (ft_strlen(str) == 0)
	{
		free(str);
		var = ft_getenv(*env, "HOME");
		if (!(str = ft_strdup(var ? var : "")))
			exit(1);
	}
	else if (ft_strlen(str) == 1 && !ft_strcmp(str, "-"))
	{
		free(str);
		var = ft_getenv(*env, "OLDPWD");
		if (!(str = ft_strdup(var ? var : "")))
			exit(1);
	}
	return (str);
}

int		change_directory(char *directory, char ***env)
{
	char	*old;
	char	*err;
	int		ret;

	old = getcwd(NULL, 255);
	ret = chdir(directory);
	if (ret == -1)
	{
		if (access(directory, F_OK) == -1)
			err = ft_strjoin3("minishell: cd: ", directory,
				": No such file or directory");
		else
			err = ft_strjoin3("minishell: cd: ", directory,
				": Permission denied");
		ft_putendl_fd(err, 2);
		free(err);
	}
	else
		*env = ft_setenv(env, "OLDPWD", old);
	free(directory);
	free(old);
	return (ret);
}

int		cd_builtin(char **argv, char ***env)
{
	char	*dir;
	int		ret;

	dir = get_directory(argv, env);
	ret = change_directory(dir, env);
	return (ret);
}
