# include "libft.h"

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
