/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:09:57 by aguiot--          #+#    #+#             */
/*   Updated: 2019/03/19 06:05:48 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlist_map(t_dlist *head, t_dlist *(*f)(t_dlist *node))
{
	t_dlist	*mapped;

	if (head)
	{
		mapped = f(head);
		mapped->next = ft_dlist_map(head->next, f);
		return (mapped);
	}
	return (NULL);
}
