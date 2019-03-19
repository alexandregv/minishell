#include "minishell.h"

int	cd_builtin(char **argv, char **env)
{
	char	*str;
	char	*err;
	int		ret;

	if ((str = ft_join_table(argv + 1, " ")) == NULL)
		return (-1);
	str[ft_strlen(str) - 1] = '\0';
	ret = chdir(str);
	if (ret == -1)
	{
		if (access(str, F_OK) == -1)
			err = ft_strjoin3("cd: ", str, ": No such file or directory");
		else
			err = ft_strjoin3("cd: ", str, ": Permission denied");
		ft_putendl(err);
		free(err);
	}
	free(str);
	return (ret);
	(void)env;
}
