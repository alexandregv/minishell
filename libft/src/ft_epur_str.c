/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epur_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 00:44:55 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/28 00:44:56 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_epur_str(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = ft_strnew(ft_strlen(str));
	while (ft_isblank(str[i]))
		++i;
	while (str[i])
	{
		if (!ft_isblank(str[i]))
			res[j++] = str[i];
		while (ft_isblank(str[i]) && ft_isblank(str[i + 1]))
			++i;
		if (ft_isblank(str[i]) && !ft_isblank(str[i + 1]))
			res[j++] = ' ';
		++i;
	}
	return (res);
}
