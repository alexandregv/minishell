#include "minishell.h"

char	*ft_getenv(char **env, char *var)
{
	while (*env)
	{
		if (!ft_strncmp(*env, var, ft_strlen(var)))
			return (*env + (ft_strchr(*env, '=') - *env + 1));
		++env;
	}
	return (NULL);
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
