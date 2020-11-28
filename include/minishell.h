/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 00:35:58 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/28 17:21:03 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <limits.h>
# include <sys/wait.h>
# include "libft.h"

extern pid_t	g_pid;
extern char	**g_env;

char	**ft_parse_path(char **env);
char	*ft_getenv(char **env, char *var);
int		echo_builtin(char **argv, char **env);
int		cd_builtin(char **argv, char ***env);
int		setenv_builtin(int argc, char **argv, char ***env);
int		unsetenv_builtin(int argc, char **argv, char ***env);
int		env_builtin(char **argv, char **env);
int		exit_builtin(char **argv);
int		where_builtin(char **path, char **argv);
char	**init_env(char **env);
int		prompt(char **env);
char	**ft_setenv(char ***env, char *var, char *value);
char	**ft_unsetenv(char **env, char *var);
int		check_builtins(char **path, char **argv, char ***env);
char	*from_path(char **path, char *file);
int		display_sig(int ret);
void	ft_handle_sigint(int sig);
int		ft_fork(char *fullpath, char **argv, char **env);
int		exec_cmd(char **path, char **argv, char **env);

#endif
