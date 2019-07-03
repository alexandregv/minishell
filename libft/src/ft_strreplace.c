/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:58:10 by aguiot--          #+#    #+#             */
/*   Updated: 2019/07/03 10:58:18 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strreplace(char *str, char *needle, char *stack)
{
	char		*res;
	char		*start;
	size_t		to_needle;
	size_t		to_end;

	if ((start = ft_strstr(str, needle)))
	{
		to_needle = start - str;
		to_end = ft_strlen(start + ft_strlen(needle));
		if ((res = ft_strnew(sizeof(char)
						* (to_needle + ft_strlen(stack) + to_end))))
			return (ft_strcat(ft_strcat(ft_strncpy(res, str, to_needle), stack),
					start + ft_strlen(needle)));
		else
			return (NULL);
	}
	return (str);
}
