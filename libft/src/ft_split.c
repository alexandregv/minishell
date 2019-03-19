#include "libft.h"

static int		count_words(char *str, int delim)
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

static char	*malloc_word(char *str, int delim)
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
