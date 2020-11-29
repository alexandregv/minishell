/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 19:31:20 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/29 19:44:40 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_1(t_dlist *cmds, char **path, char **argv, char ***env)
{
	int	argc;
	int	ret;

	argc = 0;
	while (argv[argc] != NULL)
		++argc;
	ret = 256;
	if (!ft_strcmp(argv[0], "echo"))
		ret = echo_builtin(argv, *env);
	else if (!ft_strcmp(argv[0], "cd"))
		ret = cd_builtin(argv, env);
	else if (!ft_strcmp(argv[0], "setenv"))
		ret = setenv_builtin(argc, argv, env);
	else if (!ft_strcmp(argv[0], "unsetenv"))
		ret = unsetenv_builtin(argc, argv, env);
	else if (!ft_strcmp(argv[0], "env"))
		ret = env_builtin(argv, *env);
	else if (!ft_strcmp(argv[0], "exit"))
		ret = exit_builtin(argv);
	return (ret);
	(void)cmds;
	(void)path;
}

static int	check_2(t_dlist *cmds, char **path, char **argv, char ***env)
{
	int	argc;
	int	ret;

	argc = 0;
	while (argv[argc] != NULL)
		++argc;
	ret = 256;
	if (!ft_strcmp(argv[0], "where"))
		ret = where_builtin(path, argv);
	else if (!ft_strcmp(argv[0], "pwd"))
		ret = pwd_builtin();
	else if (!ft_strcmp(argv[0], "history"))
		ret = history_builtin(cmds);
	return (ret);
	(void)cmds;
	(void)env;
}

int			check_builtins(t_dlist *cmds, char **path, char **argv, char ***env)
{
	int	argc;
	int	ret;

	argc = 0;
	while (argv[argc] != NULL)
		++argc;
	if (!argv[0])
		return (257);
	ret = 256;
	ret = check_1(cmds, path, argv, env);
	if (ret == 256)
		ret = check_2(cmds, path, argv, env);
	return (ret);
}
