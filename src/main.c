/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:52:29 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/29 15:33:17 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	g_pid;
char	**g_env;

static char	*expand_expansions(char *cmd, char **env)
{
	char	*tmpline;
	char	*var;

	tmpline = cmd;
	cmd = ft_epur_str(cmd);
	free(tmpline);
	if (ft_strchr(cmd, '~'))
	{
		tmpline = cmd;
		cmd = ft_strreplace(cmd, "~", ft_getenv(env, "HOME"));
		free(tmpline);
	}
	if (ft_strchr(cmd, '$'))
	{
		tmpline = cmd;
		ft_str_copy_to(&var, ft_strchr(cmd, '$'), ' ');
		cmd = ft_strreplace(cmd, var,
				ft_getenv(env, var + 1) ? ft_getenv(env, var + 1) : "");
		free(var);
		free(tmpline);
	}
	return (cmd);
}

int			main(int ac, char **av, char **env)
{
	char	*line;
	char	**parsed_argv;
	char	**path;
	int		ret;
	char	**chained_cmds;
	int		i;
	t_dlist	*cmds;

	g_pid = -1;
	signal(SIGINT, ft_handle_sigint);
	ret = 0;
	env = init_env(env);
	g_env = env;
	cmds = NULL;
	while (prompt(env) && get_next_line(0, &line) == 1)
	{
		if (!line)
			continue ;
		g_env = env;
		chained_cmds = ft_splitu(line, ";");
		i = 0;
		while (chained_cmds[i])
		{
			chained_cmds[i] = expand_expansions(chained_cmds[i], env);
			if (i > 0 && ft_strlen(chained_cmds[i]) > 0)
				ft_putchar('\n');
			ft_dlist_push_back(&cmds, ft_dlist_new(chained_cmds[i],
						ft_strlen(chained_cmds[i]) + 1, 1));
			if (!(path = ft_parse_path(env)))
				return (EXIT_FAILURE);
			parsed_argv = ft_splitu(chained_cmds[i++], " ");
			if ((ret = check_builtins(path, parsed_argv, &env)) == 256)
				ret = exec_cmd(path, parsed_argv, env);
			ft_free_word_table(parsed_argv);
			ft_free_word_table(path);
			if (ret >= 258)
				break ;
			if (ret == 0)
				ft_putstr_tty("[\033[32m");
			else if (ret == 257)
				continue ;
			else
				ft_putstr_tty("[\033[31m");
			ft_putnbr_tty(ret);
			ft_putstr_tty("\033[39m] ");
		}
		free(line);
		ft_free_word_table(chained_cmds);
		if (ret >= 258)
			break ;
	}
	ft_free_word_table(env);
	ft_dlist_del(&cmds, NULL);
	return (0);
	(void)ac;
	(void)av;
}
