/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_get_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:06:28 by aguiot--          #+#    #+#             */
/*   Updated: 2019/03/19 06:00:39 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlist_get_at(t_dlist *head, size_t index)
{
	t_dlist	*node;

	node = head;
	while (index > 0 && node->next)
	{
		node = node->next;
		--index;
	}
	if (index > 0)
		return (NULL);
	return (node);
}
