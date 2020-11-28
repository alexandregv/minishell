/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizet_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulaao <sboulaao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:39:25 by sboulaao          #+#    #+#             */
/*   Updated: 2020/11/28 21:12:46 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		*ft_sizet_tab(int size)
{
	int		i;
	size_t	*tab;

	i = 0;
	if (!(tab = (size_t *)ft_memalloc(sizeof(size_t) * size)))
		return (NULL);
	while (i < size)
		tab[i++] = 0;
	return (tab);
}
