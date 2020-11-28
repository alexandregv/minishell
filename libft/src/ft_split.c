/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 00:40:31 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/28 20:38:09 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *str, int delim)
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
	if ((word = ft_strnew(i)) == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != delim)
	{
		word[i] = str[i];
		++i;
	}
	word[i] = '\0';
	return (word);
}

char		**ft_split(char *str, int delim)
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
