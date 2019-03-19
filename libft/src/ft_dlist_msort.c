/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_msort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 20:17:08 by aguiot--          #+#    #+#             */
/*   Updated: 2019/03/19 05:10:27 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_dlist
	*merge(t_dlist *first, t_dlist *second, int (*cmp)(t_dlist *, t_dlist *))
{
	if (!first)
		return (second);
	if (!second)
		return (first);
	if (cmp(first, second))
	{
		first->next = merge(first->next, second, cmp);
		first->next->prev = first;
		first->prev = NULL;
		return (first);
	}
	else
	{
		second->next = merge(first, second->next, cmp);
		second->next->prev = second;
		second->prev = NULL;
		return (second);
	}
}

static t_dlist
	*split(t_dlist *head)
{
	t_dlist *fast;
	t_dlist *slow;
	t_dlist *temp;

	fast = head;
	slow = head;
	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	temp = slow->next;
	slow->next = NULL;
	return (temp);
}

t_dlist
	*ft_dlist_msort(t_dlist *head, int (*cmp)(t_dlist *, t_dlist *))
{
	t_dlist	*second;

	if (!head || !head->next)
		return (head);
	second = split(head);
	head = ft_dlist_msort(head, cmp);
	second = ft_dlist_msort(second, cmp);
	return (merge(head, second, cmp));
}
