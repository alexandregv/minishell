#include "minishell.h"

static int	usage()
{
	ft_putendl("Usage: unsetenv VARIABLE");
	return (1);
}

int	unsetenv_builtin(int argc, char **argv, char ***env)
{
	if (argc <= 1)
		return (usage());
	if (ft_getenv(*env, argv[1]) != NULL)
		*env = ft_unsetenv(*env, argv[1]);
	return (0);
}
