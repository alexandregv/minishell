/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:09:25 by aguiot--          #+#    #+#             */
/*   Updated: 2019/03/19 06:01:15 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlist_del(t_dlist **list, void (*del)(void *, size_t))
{
	t_dlist	*next;
	t_dlist	*temp;

	temp = *list;
	while (temp)
	{
		next = temp->next;
		ft_dlist_del_node(&temp, del);
		temp = next;
	}
	*list = NULL;
}
