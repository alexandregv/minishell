#include "minishell.h"

int	exit_builtin(char **argv)
{
	if (argv[1] != NULL)
	{
		if (ft_str_is_numeric(argv[1]))
			exit(ft_atoi(argv[1]));
		exit(127);
	}
	return (258);
}
