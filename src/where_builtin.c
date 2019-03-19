#include "minishell.h"

int	where_builtin(char **path, char **argv, char **env)
{
	char	*fullpath;
	char	**ptr;
	int		found;

	ptr = path;
	found = 0;
	while (*path)
	{
		fullpath = ft_strjoin3(*path, "/", argv[1]);
		if (access(fullpath, F_OK) == 0)
		{
			ft_putendl(fullpath);
			found = 1;
		}
		++path;
		free(fullpath);
	}
	if (!found)
	{
		ft_putstr(argv[1]);
		ft_putendl(" not found");
	}
	path = ptr;


	return (0);
	(void)env;
	(void)argv;
}
