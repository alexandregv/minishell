/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_iter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:09:41 by aguiot--          #+#    #+#             */
/*   Updated: 2019/03/19 05:16:20 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlist_iter(t_dlist *head, void (*f)(t_dlist *elem), int rev)
{
	t_dlist	*node;

	node = head;
	while (node)
	{
		f(node);
		if (rev)
			node = node->prev;
		else
			node = node->next;
	}
}
