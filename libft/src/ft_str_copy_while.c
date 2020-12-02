/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_copy_while.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 02:42:37 by aguiot--          #+#    #+#             */
/*   Updated: 2020/12/02 03:23:04 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int			ft_str_copy_while(char **dst, char *src, int (*f)(char))
{
	int		i;

	i = 0;
	while (f(src[i]) == 1)
		++i;
	*dst = ft_strndup(src, i);
	return (i);
}
