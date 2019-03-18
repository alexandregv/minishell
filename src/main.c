#include "minishell.h"

#define STDIN 0

void	ft_print_word_table(char **words)
{
	if (words == NULL)
		return ;
	while (*words)
		ft_putendl(*words++);
}

void	ft_free_word_table(char **words)
{
	char	**ptr;
	
	if (words == NULL)
		return ;
	ptr = words;
	while (*words)
		free(*words++);
	free(ptr);
}

int		count_words(char *str, int delim)
{
	int		count;

	count = 0;
	while (*str)
	{
		while (*str && *str == delim)
			++str;
		if (*str && *str != delim)
		{
			count++;
			while (*str && *str != delim)
				++str;
		}
	}
	return (count);
}

char	*malloc_word(char *str, int delim)
{
	char	*word;
	int		i;
	
	i = 0;
	while (str[i] && str[i] != delim)
		++i;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && str[i] != delim)
	{
		word[i] = str[i];
		++i;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, int delim)
{
	int		words;
	char	**tab;
	int		i;

	words = count_words(str, delim);
	tab = (char **)malloc(sizeof(char*) * (words + 1));
	i = 0;
	while (*str)
	{
		while (*str && *str == delim)
			++str;
		if (*str && *str != delim)
		{
			tab[i] = malloc_word(str, delim);
			++i;
			while (*str && *str != delim)
				++str;
		}
	}
	tab[i] = NULL;
	return (tab);
}

int	prompt(void)
{
	char	buff[4096 + 1];
	char	*buffptr;
	
	getcwd(buff, 4096);
	if (!(buffptr = ft_strchr(buff, '~')))
		buffptr = buff;
	ft_putstr(buffptr); //TODO: replace $HOME by '~'
	ft_putstr(" $>");
	return (1);
}

char	**parse_path(char **env)
{
	char	**path;

	while (*env)
	{
		if (!ft_strncmp(*env, "PATH", 4))
		{
			path = ft_split(*env, ':');
			//*path += 5;
			return (path);
		}
		else
			++env;
	}
	return (NULL);
}

int		main(int ac, char **av, char **env)
{
	char	*line;
	char	**path;

	while(prompt() && get_next_line(STDIN, &line))
	{
		path = parse_path(env);
		ft_print_word_table(path);
		//free(*path - 5);
		ft_free_word_table(path);
		if(!ft_strcmp(line, "exit"))
		{
			free(line);
			break ;
		}
		ft_putendl(line);
		free(line);
	}

	(void)ac;
	(void)av;
	(void)env;
	return (0);
}
