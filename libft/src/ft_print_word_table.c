# include "libft.h"

void	ft_print_word_table(char **words)
{
	if (words == NULL)
		return ;
	while (*words)
		ft_putendl(*words++);
}
