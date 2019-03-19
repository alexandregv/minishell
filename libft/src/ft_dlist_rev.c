/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_rev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 20:17:01 by aguiot--          #+#    #+#             */
/*   Updated: 2019/03/19 05:06:50 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlist_rev(t_dlist **head)
{
	t_dlist	*curr;
	t_dlist	*temp;
	t_dlist	*last;

	last = ft_dlist_last(*head);
	curr = *head;
	while (curr != NULL)
	{
		temp = curr->next;
		curr->next = curr->prev;
		curr->prev = temp;
		curr = temp;
	}
	temp = *head;
	*head = last;
}
