#include "minishell.h"

int	setenv_builtin(char **argv, char ***env)
{
	char	*var = ft_strdup("TEST=JeSuis42");
	int		i;

	i = 0;
	while (*env[i])
		ft_putendl(*env[i++]);
	ft_putendl(" 1 ========");
	ft_putendl(*env[i]);
	ft_putendl(" 2 ========");
	*env = (char **)malloc(sizeof(char) * (sizeof(*env) + ft_strlen(var) + 1));
	*env[++i] = var;
	return (0);
	(void)argv;
	(void)env;
}

int	unsetenv_builtin(char **argv, char **env)
{
	return (0);
	(void)argv;
	(void)env;
}

int	env_builtin(char **argv, char **env)
{
	if (env)
		ft_print_word_table(env);
	return (0);
	(void)argv;
	(void)env;
}
