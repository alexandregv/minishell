#include "minishell.h"

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

char	**ft_setenv(char ***env, char *var, char *val)
{
	char	*curr_var;
	char	**new_env;
	int		i;
	int		j;

	new_env = NULL;
	if ((curr_var = ft_getenv(*env, var)) != NULL)
	{
		i = 0;
		while ((*env)[i])
		{
			if (!ft_strcmp((*env)[i], ft_strjoin3(var, "=", curr_var)))
			{
				free((*env)[i]);
				(*env)[i] = ft_strjoin3(var, "=", val);
				return (*env);
			}
			++i;
		}
	}
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

char	**ft_unsetenv(char **env, char *var)
{
	int		i;
	int		j;
	int		len;
	char	**new_env;

	len = 0;
	while (env[len])
		++len;
	new_env = (char **)malloc(sizeof(char *) * len);
	i = 0;
	j = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], var, ft_strlen(var)) != NULL)
			free(env[i++]);
		new_env[j++] = env[i++];
	}
	new_env[j] = NULL;
	free(env);
	return (new_env);
}

char	**ft_parse_path(char **env)
{
	char	**parsed;
	char	*var;

	if (!(var = ft_getenv(env, "PATH")))
		return (NULL);
	parsed = ft_split(var, ':');
	return (parsed);
}

char	**init_env(char **env)
{
	char	**new;
	size_t	size;
	size_t	i;

	size = 0;
	while (env[size])
		++size;
	new = (char **)malloc(sizeof(char *) * (size + 1));
	new[size] = NULL;
	i = 0;
	while (i < size)
	{
		new[i] = ft_strdup(env[i]);
		//new[i][0] = 'z';
		++i;
	}
	return (new);
}
