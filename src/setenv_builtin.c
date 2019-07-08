#include "minishell.h"

int	setenv_builtin(char **argv, char ***env)
{
	char	*var;
	char	*val;

	var = argv[1];
	val = argv[2];

	ft_putendl(ft_strjoin3(var, "=", val));
	*env = ft_setenv(*env, var, val);
	//ft_print_word_table(*env);
	return (0);
}
