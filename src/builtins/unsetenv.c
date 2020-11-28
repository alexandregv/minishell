/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 00:35:40 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/28 03:04:19 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	usage(void)
{
	ft_putendl_tty("Usage: unsetenv VARIABLE");
	return (1);
}

int			unsetenv_builtin(int argc, char **argv, char ***env)
{
	if (argc <= 1)
		return (usage());
	if (ft_getenv(*env, argv[1]) != NULL)
		*env = ft_unsetenv(*env, argv[1]);
	return (0);
}

char		**ft_unsetenv(char **env, char *var)
{
	int		i;
	int		j;
	int		len;
	char	**new_env;

	len = 0;
	while (env[len] != NULL)
		++len;
	new_env = (char **)malloc(sizeof(char *) * len);
	i = 0;
	j = 0;
	while (env[i] != NULL)
	{
		if (ft_strnstr(env[i], var, ft_strlen(var)) != NULL)
			free(env[i++]);
		else
			new_env[j++] = env[i++];
	}
	new_env[j] = NULL;
	free(env);
	return (new_env);
}
