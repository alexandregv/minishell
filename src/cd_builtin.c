/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 08:55:04 by aguiot--          #+#    #+#             */
/*   Updated: 2019/07/03 16:10:12 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd_builtin(char **argv, char **env)
{
	char	*str;
	char	*err;
	char	*old;
	int		ret;

	if ((str = ft_join_table(argv + 1, " ")) == NULL)
		return (-1);
	str[ft_strlen(str) - 1] = '\0';
	if (ft_strlen(str) == 0)
	{
		free(str);
		if (!(str = ft_strdup(ft_getenv(env, "HOME"))))
			exit(1); //TODO: Bonus /home/getpwuid() ?
	}
	else if (ft_strlen(str) == 1 && !ft_strcmp(str, "-"))
	{
		free(str);
		if (!(str = ft_strdup(ft_getenv(env, "OLDPWD"))))
			exit(1);
	}
	old = getcwd(NULL, 255);
	ret = chdir(str);
	if (ret == -1)
	{
		if (access(str, F_OK) == -1)
			err = ft_strjoin3("cd: ", str, ": No such file or directory");
		else
			err = ft_strjoin3("cd: ", str, ": Permission denied");
		ft_putendl_fd(err, 2);
		free(err);
	}
	else
		env = ft_setenv(env, "OLDPWD", old);
	free(old);
	free(str);
	return (ret);
}
