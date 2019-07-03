#include "minishell.h"

int	where_builtin(char **path, char **argv, char **env)
{
	char	*fullpath;
	char	**ptr;
	int		found;

	if (!argv[1])
		return (0);
	ptr = path;
	found = 0;
	while (*path && !found)
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
	if (!ft_strcmp(argv[1], "echo") //TODO: :nauseated_face:
			|| !ft_strcmp(argv[1], "cd")
			|| !ft_strcmp(argv[1], "setenv")
			|| !ft_strcmp(argv[1], "unsetenv")
			|| !ft_strcmp(argv[1], "env")
			|| !ft_strcmp(argv[1], "exit")
			|| !ft_strcmp(argv[1], "where"))
	{
		ft_putstr(argv[1]);
		ft_putendl(": shell built-in command");
		found = 1;
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
