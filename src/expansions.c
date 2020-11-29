/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:52:29 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/29 18:08:49 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*tilde_expansion(char *cmd, char **env)
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

char	*var_expansion(char *cmd, char **env)
{
	char	*tmp;
	char	*var;
	char	*val;

	if (ft_strchr(cmd, '$'))
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

char	*expand_expansions(char *cmd, char **env)
{
	char	*tmp;

	tmp = cmd;
	cmd = ft_epur_str(cmd);
	free(tmp);
	cmd = tilde_expansion(cmd, env);
	cmd = var_expansion(cmd, env);
	return (cmd);
}
