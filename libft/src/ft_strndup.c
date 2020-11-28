/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:12:56 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/28 20:25:58 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(char const *s1, size_t n)
{
	char *s2;

	if ((s2 = ft_strnew(n)) == NULL)
		return (NULL);
	ft_strncpy(s2, s1, n);
	return (s2);
}
