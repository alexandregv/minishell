/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:32:04 by aguiot--          #+#    #+#             */
/*   Updated: 2018/11/19 18:27:59 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strlowcase(char *s)
{
	char	*p;

	p = s;
	while (p && *p)
	{
		if (ft_isupper(*p))
			*p += 32;
		++p;
	}
	return (s);
}
