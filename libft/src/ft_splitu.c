#include <stdlib.h>
#include "libft.h"

static int	charset_contains(char *charset, char c)
{
	while (*charset != '\0')
		if (*(charset++) == c)
			return (1);
	return (0);
}

static int	count_words(char *str, char *charset)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (charset_contains(charset, str[i])
				&& (i != 0 && !charset_contains(charset, str[i - 1])))
			++count;
		i++;
	}
	if ((i != 0 && !charset_contains(charset, str[i - 1])))
		++count;
	return (count);
}

static char	*skip_separators(char *str, char *charset)
{
	while (*str != '\0' && charset_contains(charset, *str))
		++str;
	return (str);
}

static char	*copy_to(char *str, char *charset, char **words, int i_words)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && !charset_contains(charset, str[i]))
		++i;
	if ((words[i_words] = ft_strnew(i)) == NULL)
		return (NULL);
	words[i_words][i] = '\0';
	i = 0;
	while (str[i] != '\0' && !charset_contains(charset, str[i]))
	{
		words[i_words][i] = str[i];
		++i;
	}
	return (str + i);
}

char		**ft_splitu(char *str, char *charset)
{
	int		words_count;
	char	**words;
	int		i;

	words_count = count_words(str, charset);
	if (!(words = (char **)ft_memalloc(sizeof(char *) * (words_count + 1))))
		return (NULL);
	words[words_count] = NULL;
	i = 0;
	while (i < words_count)
	{
		str = skip_separators(str, charset);
		str = copy_to(str, charset, words, i);
		if (str == NULL)
		{
			while (--i >= 0)
				free(words[i--]);
			free(words);
			return (NULL);
		}
		++i;
	}
	return (words);
}
