/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:19:59 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/28 18:00:13 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_fork(char *fullpath, char **argv, char **env)
{
	pid_t	pid;
	int		ret;

	ret = 0;
	pid = fork();
	if (pid < 0)
		ft_die("fork() failed, please check max process limits", -1);
	if (pid > 0)
	{
		g_pid = pid;
		wait(&ret);
		g_pid = -1;
		free(fullpath);
		return (display_sig(ret));
	}
	else if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		ret = execve(fullpath, argv, env);
		free(fullpath);
		return (259);
	}
	return (ret);
}

int	exec_cmd(char **path, char **argv, char **env)
{
	char	*fullpath;

	if ((ft_strchr(argv[0], '/') == NULL)
			&& (fullpath = from_path(path, argv[0])) != NULL)
	{
		return (ft_fork(fullpath, argv, env));
	}
	else if (access(argv[0], F_OK) == 0)
	{
		fullpath = ft_strdup(argv[0]);
		return (ft_fork(fullpath, argv, env));
	}
	else
	{
		fullpath = ft_strjoin("minishell: command not found: ", argv[0]);
		ft_putendl_fd(fullpath, 2);
		free(fullpath);
		return (127);
	}
}

int	check_builtins(char **path, char **argv, char ***env)
{
	int		argc;

	argc = 0;
	while (argv[argc] != NULL)
		++argc;
	if (!argv[0])
		return (257);
	if (!ft_strcmp(argv[0], "echo"))
		return (echo_builtin(argv, *env));
	else if (!ft_strcmp(argv[0], "cd"))
		return (cd_builtin(argv, env));
	else if (!ft_strcmp(argv[0], "setenv"))
		return (setenv_builtin(argc, argv, env));
	else if (!ft_strcmp(argv[0], "unsetenv"))
		return (unsetenv_builtin(argc, argv, env));
	else if (!ft_strcmp(argv[0], "env"))
		return (env_builtin(argv, *env));
	else if (!ft_strcmp(argv[0], "exit"))
		return (exit_builtin(argv));
	else if (!ft_strcmp(argv[0], "where"))
		return (where_builtin(path, argv));
	return (256);
}
