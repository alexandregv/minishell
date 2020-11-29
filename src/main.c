/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:52:29 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/29 20:18:17 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	g_pid = -1;
char	**g_env = (char *[]) { NULL };

int			main(int ac, char **av, char **env)
{
	char	*line;
	int		ret;
	char	**chained_cmds;
	t_dlist	*cmds;

	signal(SIGINT, ft_handle_sigint);
	env = init_env(ac, av, env);
	cmds = NULL;
	while (prompt(env) && get_next_line(0, &line) == 1)
	{
		if (!line)
			continue ;
		g_env = env;
		chained_cmds = ft_splitu(line, ";");
		ret = exec_cmds(0, &cmds, chained_cmds, &env);
		free(line);
		ft_free_word_table(chained_cmds);
		if (ret >= 258)
			break ;
	}
	ft_free_word_table(env);
	ft_dlist_del(&cmds, NULL);
	return (0);
}
