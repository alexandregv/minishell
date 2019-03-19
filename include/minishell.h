#ifndef MINISHELL_H
# define MINISHELL_H

# include <limits.h>
# include "libft.h"

char	**ft_parse_path(char **env);
char	*ft_getenv(char **env, char *var);

int		echo_builtin(char **argv, char **env);
int		cd_builtin(char **argv, char **env);
int		setenv_builtin(char **argv, char ***env);
int		unsetenv_builtin(char **argv, char **env);
int		env_builtin(char **argv, char **env);
int		exit_builtin(char **argv, char **env);
int		where_builtin(char **path, char **argv, char **env);
char	**init_env(char **env);
int		prompt(char **env);

#endif
