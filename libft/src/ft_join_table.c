# include "libft.h"

char	*ft_join_table(char **words, char *sep)
{
	char	**ptr;
	char	*res;
	size_t	size;
	
	if (!words)
		return (NULL);
	size = 0;
	ptr = words;
	while (*ptr)
	{
		size += ft_strlen(*ptr++);
		if (sep && *ptr != NULL)
			size += ft_strlen(sep);
	}
	res = ft_strnew(size);
	ptr = words;
	while (*ptr)
	{
		res = ft_strcat(res, *ptr++);
		if (sep && *ptr != NULL)
			res = ft_strcat(res, sep);
	}
	return (res);
}
