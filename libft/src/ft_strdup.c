/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:54:54 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/28 20:22:43 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(char const *s1)
{
	char *s2;

	if ((s2 = ft_strnew(ft_strlen(s1))) == NULL)
		return (NULL);
	ft_strcpy(s2, s1);
	return (s2);
}
