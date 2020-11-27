#include "minishell.h"

static int	display_sig(int ret)
{
	if (WIFEXITED(ret))
		return (WEXITSTATUS(ret));
	else if (WIFSIGNALED(ret))
	{
		if (WTERMSIG(ret) == SIGBUS)
			ft_putendl_fd("Bus Error", 2);
		else if (WTERMSIG(ret) == SIGSEGV)
			ft_putendl_fd("Seg Fault", 2);
		else if (WTERMSIG(ret) == SIGQUIT)
			ft_putendl_fd("Quitted", 2);
		else if (WTERMSIG(ret) == SIGFPE)
			ft_putendl_fd("Floating Point Exception", 2);
		else if (WTERMSIG(ret) == SIGALRM)
			ft_putendl_fd("Timed out", 2);
		else if (WTERMSIG(ret) == SIGABRT)
			ft_putendl_fd("Aborted", 2);
	}
	return (1);
}

char		*from_path(char **path, char *file)
{
	char	*fullpath;
	int		in;

	in = 0;
	while (*path)
	{
		fullpath = ft_strjoin3(*path, "/", file);
		if (access(fullpath, F_OK) == 0)
			return (fullpath);
		++path;
		++in;
		free(fullpath);
	}
	return (NULL);
}

int			exec_cmd(char **path, char **argv, char **env)
{
	pid_t	pid;
	int		ret;
	char	*fullpath;

	if (access(argv[0], F_OK) == 0)
		fullpath = ft_strdup(argv[0]);
	else if (!(fullpath = from_path(path, argv[0])))
	{
		fullpath = ft_strjoin("minishell: command not found: ", argv[0]);
		ft_putendl_fd(fullpath, 2);
		free(fullpath);
		return (127);
	}
	ret = 0;
	pid = fork();
	if (pid < 0)
		ft_die("fork() failed, please check max process limits", -1);
	if (pid > 0)
	{
		wait(&ret);
		return (display_sig(ret));
	}
	else if (pid == 0)
	{
		ret = execve(fullpath, argv, env);
		free(fullpath);
		exit(ret);
	}
	return (ret);
}

int			check_builtins(char **path, char **argv, char **env)
{
	int argc;

	argc = 0;
	while (argv[argc] != NULL)
		++argc;
	if (!argv[0])
		return (257);
	if (!ft_strcmp(argv[0], "echo"))
		return (echo_builtin(argv, env));
	else if (!ft_strcmp(argv[0], "cd"))
		return (cd_builtin(argv, env));
	else if (!ft_strcmp(argv[0], "setenv"))
		return (setenv_builtin(argc, argv, &env));
	else if (!ft_strcmp(argv[0], "unsetenv"))
		return (unsetenv_builtin(argv, env));
	else if (!ft_strcmp(argv[0], "env"))
		return (env_builtin(argv, env));
	else if (!ft_strcmp(argv[0], "exit"))
		return (exit_builtin(argv, env));
	else if (!ft_strcmp(argv[0], "where"))
		return (where_builtin(path, argv, env));
	return (256);
}

int			main(int ac, char **av, char **env)
{
	char	*line;
	char	*tmpline;
	char	**parsed_argv;
	char	**path;
	int		ret;
	char	**chained_cmds;
	int		i;
	t_dlist	*cmds;

	env = init_env(env);
	//ft_print_word_table(env);
	//env = ft_setenv(env, "TEST", "test");
	//env = ft_setenv(env, "T", "test");
	cmds = NULL;
	while (prompt(env) && get_next_line(0, &line))
	{
		if (!*line)
			continue ;	
		chained_cmds = ft_split(line, ';');
		i = 0;
		while (chained_cmds[i])
		{
			tmpline = chained_cmds[i];
			chained_cmds[i] = ft_epur_str(chained_cmds[i]);
			free(tmpline);
			if (ft_strchr(chained_cmds[i], '~'))
			{
				tmpline = chained_cmds[i];
				chained_cmds[i] = ft_strreplace(chained_cmds[i], "~", ft_getenv(env, "HOME"));
				free(tmpline);
			}
			if (ft_strchr(chained_cmds[i], '$'))
			{
				tmpline = chained_cmds[i];
				char *var;
				ft_str_copy_to(&var, ft_strchr(chained_cmds[i], '$'), ' ');
				chained_cmds[i] = ft_strreplace(chained_cmds[i], var, ft_getenv(env, var + 1) ?: "");
				free(var);
				free(tmpline);
			}

			if (i > 0)
				ft_putchar('\n');
			ft_dlist_push_back(&cmds, ft_dlist_new(chained_cmds[i],
						ft_strlen(chained_cmds[i]) + 1, 1));
			if (!(path = ft_parse_path(env)))
				return (EXIT_FAILURE);
			parsed_argv = ft_split(chained_cmds[i++], ' ');
			if ((ret = check_builtins(path, parsed_argv, env)) == 256)
				ret = exec_cmd(path, parsed_argv, env);
			if (ret == 0)
				ft_putstr("[\033[32m");
			else if (ret == 257)
				continue ;
			else
				ft_putstr("[\033[31m");
			ft_putnbr(ret);
			ft_putstr("\033[39m] ");
		}
		free(line);
		//ft_free_word_table(path);
	}
	ft_dlist_del(&cmds, NULL);
	return (0);
	(void)ac;
	(void)av;
}
