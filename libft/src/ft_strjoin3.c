/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:17:11 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/28 20:20:44 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin3(char const *s1, char const *s2, char const *s3)
{
	char	*cat;

	if (!s1 || !s2 || !s3)
		return (NULL);
	if ((cat = ft_strnew(ft_strlen(s1)
					+ ft_strlen(s2)
					+ ft_strlen(s3))) == NULL)
		return (NULL);
	cat = ft_strcat(ft_strcat(ft_strcat(cat, s1), s2), s3);
	return (cat);
}
