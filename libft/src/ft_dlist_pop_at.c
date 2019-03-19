/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_pop_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:07:26 by aguiot--          #+#    #+#             */
/*   Updated: 2019/03/19 05:20:35 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlist_pop_at(t_dlist **head, size_t index)
{
	t_dlist	*temp;
	t_dlist	*poped;

	if (index == 0)
	{
		poped = *head;
		*head = (*head)->next;
		poped->next = NULL;
		return (poped);
	}
	else
	{
		temp = *head;
		while (--index > 0 && temp->next)
			temp = temp->next;
		poped = temp->next;
		temp->next = poped->next;
		poped->next = NULL;
	}
	return (poped);
}
