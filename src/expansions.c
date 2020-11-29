/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:52:29 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/29 16:05:03 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_expansions(char *cmd, char **env)
{
	char	*tmpline;
	char	*var;
	char	*val;

	tmpline = cmd;
	cmd = ft_epur_str(cmd);
	free(tmpline);
	if (ft_strchr(cmd, '~'))
	{
		tmpline = cmd;
		val = ft_getenv(env, "HOME");
		cmd = ft_strreplace(cmd, "~", val ? val : "");
		free(tmpline);
	}
	if (ft_strchr(cmd, '$'))
	{
		tmpline = cmd;
		ft_str_copy_to(&var, ft_strchr(cmd, '$'), ' ');
		val = ft_getenv(env, var + 1);
		cmd = ft_strreplace(cmd, var, val ? val : "");
		free(var);
		free(tmpline);
	}
	return (cmd);
}
