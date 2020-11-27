#include "minishell.h"

static int	usage()
{
	ft_putendl("Usage: setenv VARIABLE value");
	return (1);
}

int	setenv_builtin(int argc, char **argv, char ***env)
{
	char	*var;
	char	*val;
	char	*eq;

	if (argc >= 3)
		val = argv[2];
	else if (argc == 2)
	{
		eq = ft_strchr(argv[1], '=');
		*eq = '\0';
		if (eq != NULL)
			val = eq + 1;
		else
			return (usage());
	}
	else
		return (usage());
	var = argv[1];
	*env = ft_setenv(*env, var, val);
	return (0);
}
