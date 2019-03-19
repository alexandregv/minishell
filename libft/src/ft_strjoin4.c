/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:17:11 by aguiot--          #+#    #+#             */
/*   Updated: 2019/03/19 06:18:56 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strjoin4(char const *s1, char const *s2, char const *s3, char const *s4)
{
	char	*cat;

	if (!s1 || !s2 || !s3 || !s4)
		return (NULL);
	if ((cat = ft_strnew(ft_strlen(s1)
					+ ft_strlen(s2)
					+ ft_strlen(s3)
					+ ft_strlen(s4))) == NULL)
		return (NULL);
	cat = ft_strcat(ft_strcat(ft_strcat(ft_strcat(cat, s1), s2), s3), s4);
	return (cat);
}
