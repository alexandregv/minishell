/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epur_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:38:15 by aguiot--          #+#    #+#             */
/*   Updated: 2019/07/29 10:16:39 by aguiot--         ###   ########.fr       */
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

//char	*ft_epur_str(char *str)
//{
//	char	*res;
//
//	res = ft_strnew(ft_strlen(str));
//    while (ft_isblank(*str))
//        ++str;
//    while (*str)
//    {
//        if (!ft_isblank(*str))
//			*(res++) = *str;
//        while (ft_isblank(*str) && ft_isblank(*(str + 1)))
//            ++str;
//        if (ft_isblank(*str) && !ft_isblank(*(str + 1)))
//			*(res++) = ' ';
//        ++str;
//    }
//	return (res);
//}
