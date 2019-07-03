#include "minishell.h"

static int		display_sig(int ret)
{
	if (WIFEXITED(ret))
	{
		if (WEXITSTATUS(ret) == EXIT_SUCCESS)
			ft_putendl_fd("OK", 1);
		else
			ft_putendl_fd("KO", 2);
		return ((WEXITSTATUS(ret) == EXIT_SUCCESS) ? 0 : -1);
	}
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
	return (-1);
}

char	*from_path(char **path, char *file)
{
	char	*fullpath;
	//char	**ptr;
	int		in;

	//ptr = path;
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

int	exec_cmd(char **path, char **argv, char **env)
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
		return (-1);
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
		//execve("/bin/ls", (char *[]) {"ls", "-l", "-G", NULL}, env);
		ret = execve(fullpath, argv, env);
		free(fullpath);
		exit(ret);
	}
	return (0);
}

void	print_node(t_dlist *node)
{
	ft_putendl(node->content);
}

int		check_builtins(char **path, char **argv, char **env)
{
	//int		ret;

	//ret = 0;
	if (!ft_strcmp(argv[0], "echo"))
		return (echo_builtin(argv, env));
	else if (!ft_strcmp(argv[0], "cd"))
		return (cd_builtin(argv, env));
	else if (!ft_strcmp(argv[0], "setenv"))
		return (setenv_builtin(argv, &env));
	else if (!ft_strcmp(argv[0], "unsetenv"))
		return (unsetenv_builtin(argv, env));
	else if (!ft_strcmp(argv[0], "env"))
		return (env_builtin(argv, env));
	else if (!ft_strcmp(argv[0], "exit"))
		return (exit_builtin(argv, env));
	else if (!ft_strcmp(argv[0], "where"))
		return (where_builtin(path, argv, env));
	return (-42);
}

int		main(int ac, char **av, char **env)
{
	char	*line;
	char	**parsed_argv;
	char	**path;
	int		ret;
	t_dlist	*cmds;

	env = init_env(env);
	//ft_print_word_table(env);
	cmds = NULL;
	while(prompt(env) && get_next_line(0, &line))
	{
		if (!*line)
			continue ;
		ft_dlist_push_back(&cmds, ft_dlist_new(line, ft_strlen(line) + 1, 1));
		if (!(path = ft_parse_path(env)))
			return (EXIT_FAILURE);

		parsed_argv = ft_split(line, ' ');
		if ((ret = check_builtins(path, parsed_argv, env)) == -42)
			ret = exec_cmd(path, parsed_argv, env);
		ft_putchar('[');
		if (ret == 0)
			ft_putstr("\033[32m");
		else
			ft_putstr("\033[31m");
		ft_putnbr(ret);
			ft_putstr("\033[39m");
		ft_putstr("] ");

		free(line);
		*path -= 5;
		ft_free_word_table(path);
	}
	//ft_dlist_iter(list, print_node, 0);
	ft_dlist_del(&cmds, NULL);

	(void)ac;
	(void)av;
	return (0);
}
