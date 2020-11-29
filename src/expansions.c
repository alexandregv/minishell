/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:52:29 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/29 18:31:01 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*tilde_expansion(char *cmd, char **env)
{
	char	*tmp;
	char	*val;

	if (ft_strchr(cmd, '~'))
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
	char	*tmp;
	char	*var;
	char	*val;

	dol = ft_strchr(cmd, '$');
	if (dol && *(dol + 1) != '?' && *(dol + 1) != '$' && *(dol + 1) != '\0')
	{
		tmp = cmd;
		ft_str_copy_to(&var, ft_strchr(cmd, '$'), ' ');
		val = ft_getenv(env, var + 1);
		cmd = ft_strreplace(cmd, var, val ? val : "");
		free(var);
		free(tmp);
	}
	return (cmd);
}

static char	*dollar_expansion(char *cmd, char **env)
{
	char	*dol;
	char	*pid;

	dol = ft_strchr(cmd, '$');
	if (dol && *(dol + 1) == '$')
	{
		pid = ft_itoa((int)getpid());
		cmd = ft_strreplace(cmd, "$$", pid);
		free(pid);
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
	cmd = var_expansion(cmd, env);
	cmd = dollar_expansion(cmd, env);
	return (cmd);
}
