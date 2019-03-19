/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_push_at.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:07:26 by aguiot--          #+#    #+#             */
/*   Updated: 2019/03/19 05:19:40 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlist_push_at(t_dlist **head, t_dlist *node, size_t index)
{
	t_dlist	*temp;

	if (index == 0)
	{
		if (*head == NULL)
			*head = node;
		else
		{
			(*head)->prev = node;
			node->next = *head;
			*head = node;
		}
		node->prev = NULL;
	}
	else
	{
		temp = *head;
		while (--index > 0 && temp->next)
			temp = temp->next;
		node->next = temp->next;
		temp->next = node;
		node->prev = temp;
	}
	return (node);
}
