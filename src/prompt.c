#include "minishell.h"

int	prompt(char **env)
{
	char	buff[4096 + 1];
	char	*buffptr;
	char	*home;

	getcwd(buff, 4096);
	home = ft_getenv(env, "HOME");
	if (home != NULL)
	{
		home += 5;
		if (!ft_strncmp(buff, home, ft_strlen(home)))
		{
			buffptr = buff + ft_strlen(home);
			ft_putchar('~');
		}
		else
			buffptr = buff;
		home -= 5;
		free(home);
	}
	else
		buffptr = buff;
	ft_putstr(buffptr);
	ft_putstr(" $>");
	return (1);
}
