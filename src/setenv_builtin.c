#include "minishell.h"

static int	usage(void)
{
	ft_putendl_tty("Usage: setenv VARIABLE value");
	return (1);
}

int			setenv_builtin(int argc, char **argv, char ***env)
{
	char	*var;
	char	*val;
	char	*eq;

	if (argc >= 3)
		val = argv[2];
	else if (argc == 2)
	{
		eq = ft_strchr(argv[1], '=');
		if (eq == NULL)
			return (usage());
		val = eq + 1;
		*eq = '\0';
	}
	else
		return (usage());
	var = argv[1];
	*env = ft_setenv(env, var, val);
	return (0);
}

static int	new_var(char ***env, char *var, char *val, char *curr_var)
{
	int		i;

	i = 0;
	while ((*env)[i])
	{
		if (!ft_strcmp((*env)[i], ft_strjoin3(var, "=", curr_var)))
		{
			free((*env)[i]);
			(*env)[i] = ft_strjoin3(var, "=", val);
			return (1);
		}
		++i;
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
		new_env = (char **)malloc(sizeof(char *) * (i + 2));
		j = 0;
		while (j < i)
		{
			new_env[j] = ft_strdup((*env)[j]);
			++j;
		}
		new_env[j] = ft_strjoin3(var, "=", val);
		new_env[++j] = NULL;
	}
	ft_free_word_table(*env);
	return (new_env);
}
