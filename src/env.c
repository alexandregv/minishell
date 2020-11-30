/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 00:35:02 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/30 01:56:18 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**set_last_exit_code(int ret, char ***env)
{
	char	*str;

	str = ft_itoa(ret);
	*env = ft_setenv(env, "?", str);
	free(str);
	return (*env);
}

char		*ft_getenv(char **env, char *var)
{
	unsigned int n;

	while (env && *env)
	{
		n = ft_strchr(*env, '=') - *env;
		if (ft_strncmp(*env, var, n) == 0 && ft_strlen(var) == n)
			return (n + *env + 1);
		++env;
	}
	return (NULL);
}

static char	**set_standard_vars(int ac, char **av, char ***env)
{
	char	**new;
	char	actualpath[PATH_MAX + 1];
	char	*shlvl_str;
	int		shlvl_int;

	new = *env;
	if (ac >= 1)
		new = ft_setenv(env, "SHELL", realpath(av[0], actualpath));
	shlvl_str = ft_getenv(*env, "SHLVL");
	shlvl_int = shlvl_str == NULL ? 1 : ft_atoi(shlvl_str) + 1;
	shlvl_str = ft_itoa(shlvl_int);
	new = ft_setenv(&new, "SHLVL", shlvl_str);
	free(shlvl_str);
	return (new);
}

char		**init_env(int ac, char **av, char **env)
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
	new = set_standard_vars(ac, av, &new);
	return (new);
}
