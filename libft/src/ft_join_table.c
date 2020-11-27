/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 00:42:40 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/28 00:42:48 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
