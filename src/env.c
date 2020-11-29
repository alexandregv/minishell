/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 00:35:02 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/29 19:09:07 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**set_last_exit_code(int ret, char ***env)
{
	char	*str;

	str = ft_itoa(ret);
	*env = ft_setenv(env, "?", str);
	free(str);
	return (*env);
}

char	*ft_getenv(char **env, char *var)
{
	unsigned int n;

	while (*env)
	{
		n = ft_strchr(*env, '=') - *env;
		if (ft_strncmp(*env, var, n) == 0 && ft_strlen(var) == n)
			return (n + *env + 1);
		++env;
	}
	return (NULL);
}

char	**init_env(char **env)
{
	char	**new;
	size_t	size;
	size_t	i;

	size = 0;
	while (env[size])
		++size;
	new = (char **)ft_memalloc(sizeof(char *) * (size + 1));
	new[size] = NULL;
	i = 0;
	while (i < size)
	{
		new[i] = ft_strdup(env[i]);
		++i;
	}
	return (new);
}
