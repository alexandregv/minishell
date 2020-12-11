/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:52:29 by aguiot--          #+#    #+#             */
/*   Updated: 2020/12/11 18:46:53 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_alnum_or_questionmark(char c)
{
	return (ft_isalnum(c) || c == '?');
}

static char	*tilde_expansion(char *cmd, char **env)
{
	char	*tmp;
	char	*val;

	while (ft_strchr(cmd, '~') != NULL)
	{
		tmp = cmd;
		val = ft_getenv(env, "HOME");
		cmd = ft_strreplace(cmd, "~", val ? val : "");
		free(tmp);
	}
	return (cmd);
}

static char	*var_expansion(char *cmd, char **env)
{
	char	*dol;
	char	*tmp1;
	char	*tmp2;
	char	*var;
	char	*val;

	while ((dol = ft_strchr(cmd, '$')) != NULL && *(dol + 1) != '\0'
		&& is_alnum_or_questionmark(*(dol + 1)))
	{
		tmp1 = cmd;
		ft_str_copy_while(&var, ft_strchr(cmd, '$') + 1,
			&is_alnum_or_questionmark);
		val = ft_getenv(env, var);
		tmp2 = var;
		var = ft_strjoinfree(ft_strdup("$"), var, ft_strlen(var));
		cmd = ft_strreplace(cmd, var, val ? val : "");
		free(var);
		free(tmp1);
		free(tmp2);
	}
	return (cmd);
}

static char	*dollar_expansion(char *cmd, char **env)
{
	char	*tmp;
	char	*pid;

	while (ft_strstr(cmd, "$$") != NULL)
	{
		pid = ft_itoa((int)getpid());
		tmp = cmd;
		cmd = ft_strreplace(cmd, "$$", pid);
		free(pid);
		free(tmp);
	}
	return (cmd);
	(void)env;
}

char		*expand_expansions(char *cmd, char **env)
{
	char	*tmp;

	tmp = cmd;
	cmd = ft_epur_str(cmd);
	free(tmp);
	cmd = tilde_expansion(cmd, env);
	cmd = dollar_expansion(cmd, env);
	cmd = var_expansion(cmd, env);
	return (cmd);
}
