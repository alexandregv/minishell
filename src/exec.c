/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:19:59 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/29 18:48:27 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_fork(char *fullpath, char **argv, char **env)
{
	pid_t	pid;
	int		ret;

	ret = 0;
	pid = fork();
	if (pid < 0)
		print_error("fork() failed, please check max process limits",
			ft_strdup(""), -1);
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

static char	**parse_arg(char **chained_cmds, int i, t_dlist **cmds, char ***env)
{
	chained_cmds[i] = expand_expansions(chained_cmds[i], *env);
	if (i > 0 && ft_strlen(chained_cmds[i]) > 0)
		ft_putchar('\n');
	ft_dlist_push_back(cmds, ft_dlist_new(chained_cmds[i],
				ft_strlen(chained_cmds[i]) + 1, 1));
	return (ft_splitu(chained_cmds[i], " "));
}

int			exec_cmds(t_dlist **cmds, char **chained_cmds, char ***env)
{
	char	**path;
	char	**parsed_argv;
	int		i;
	int		ret;

	i = 0;
	while (chained_cmds[i])
	{
		if ((parsed_argv = parse_arg(chained_cmds, i++, cmds, env)) == NULL
			|| (path = ft_parse_path(*env)) == NULL)
			return (EXIT_FAILURE);
		if ((ret = check_builtins(path, parsed_argv, env)) == 256)
			ret = exec_cmd(path, parsed_argv, *env);
		ft_free_word_table(parsed_argv);
		ft_free_word_table(path);
		if (ret >= 258)
			break ;
		else if (ret == 257)
			continue ;
		ft_putstr_tty(ret == 0 ? "[\033[32m" : "[\033[31m");
		ft_putnbr_tty(ret);
		ft_putstr_tty("\033[39m] ");
	}
	return (ret);
}

int			exec_cmd(char **path, char **argv, char **env)
{
	char	*fullpath;

	if ((ft_strchr(argv[0], '/') == NULL)
			&& (fullpath = from_path(path, argv[0])) != NULL)
	{
		if (access(fullpath, X_OK) == 0)
			return (ft_fork(fullpath, argv, env));
		else
			return (
				print_error("permission denied: ", fullpath, 126));
	}
	else if (access(argv[0], F_OK) == 0)
	{
		if (access(argv[0], X_OK) == 0)
			return (ft_fork(ft_strdup(argv[0]), argv, env));
		else
			return (print_error("permission denied: ",
						ft_strdup(argv[0]), 126));
	}
	else
		return (print_error("command not found: ",
					ft_strdup(argv[0]), 127));
}

int			check_builtins(char **path, char **argv, char ***env)
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
	else if (!ft_strcmp(argv[0], "pwd"))
		return (pwd_builtin());
	return (256);
}
