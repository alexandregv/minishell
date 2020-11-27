#include "minishell.h"

int	env_builtin(char **argv, char **env)
{
	if (env)
		ft_print_word_table(env);
	return (0);
	(void)argv;
	(void)env;
}
