/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:52:29 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/28 19:50:01 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	g_pid;
char	**g_env;

int			main(int ac, char **av, char **env)
{
	char	*line;
	char	*tmpline;
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
		chained_cmds = ft_split(line, ';');
		i = 0;
		while (chained_cmds[i])
		{
			tmpline = chained_cmds[i];
			chained_cmds[i] = ft_epur_str(chained_cmds[i]);
			free(tmpline);
			if (ft_strchr(chained_cmds[i], '~'))
			{
				tmpline = chained_cmds[i];
				chained_cmds[i] = ft_strreplace(chained_cmds[i], "~",
						ft_getenv(env, "HOME"));
				free(tmpline);
			}
			if (ft_strchr(chained_cmds[i], '$'))
			{
				tmpline = chained_cmds[i];
				char *var;
				ft_str_copy_to(&var, ft_strchr(chained_cmds[i], '$'), ' ');
				chained_cmds[i] = ft_strreplace(chained_cmds[i], var,
						ft_getenv(env, var + 1) ? ft_getenv(env, var + 1) : "");
				free(var);
				free(tmpline);
			}
			if (i > 0 && ft_strlen(chained_cmds[i]) > 0)
				ft_putchar('\n');
			ft_dlist_push_back(&cmds, ft_dlist_new(chained_cmds[i],
						ft_strlen(chained_cmds[i]) + 1, 1));
			if (!(path = ft_parse_path(env)))
				return (EXIT_FAILURE);
			parsed_argv = ft_split(chained_cmds[i++], ' ');
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
