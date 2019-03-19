/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:06:11 by aguiot--          #+#    #+#             */
/*   Updated: 2019/03/19 05:15:34 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_dlist_size(t_dlist *head)
{
	t_dlist	*temp;
	size_t	size;

	size = 0;
	temp = head;
	while (temp)
	{
		temp = temp->next;
		++size;
	}
	return (size);
}
