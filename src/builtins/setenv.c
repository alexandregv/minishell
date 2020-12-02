/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 00:35:29 by aguiot--          #+#    #+#             */
/*   Updated: 2020/12/02 02:38:17 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	usage(void)
{
	ft_putendl_tty("Usage: setenv VARIABLE value");
	return (1);
}

int			setenv_builtin(int argc, char **argv, char ***env)
{
	if (argc < 3)
		return (usage());
	*env = ft_setenv(env, argv[1], argv[2]);
	return (0);
}

static int	new_var(char ***env, char *var, char *val, char *curr_var)
{
	int		i;
	char	*join;

	i = 0;
	while ((*env)[i])
	{
		join = ft_strjoin3(var, "=", curr_var);
		if (!ft_strcmp((*env)[i], join))
		{
			free(join);
			free((*env)[i]);
			(*env)[i] = ft_strjoin3(var, "=", val);
			return (1);
		}
		++i;
		free(join);
	}
	return (0);
}

char		**ft_setenv(char ***env, char *var, char *val)
{
	char	*curr;
	char	**new_env;
	int		i;
	int		j;

	new_env = NULL;
	if ((curr = ft_getenv(*env, var)) != NULL && new_var(env, var, val, curr))
		return (*env);
	else
	{
		i = 0;
		while ((*env)[i] != NULL)
			++i;
		new_env = (char **)ft_memalloc(sizeof(char *) * (i + 2));
		j = 0;
		while (j < i)
		{
			new_env[j] = ft_strdup((*env)[j]);
			++j;
		}
		new_env[j] = ft_strjoin3(var, "=", val);
		new_env[++j] = NULL;
	}
	ft_free_word_table(env);
	return (new_env);
}
