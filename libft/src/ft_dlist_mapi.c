/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_mapi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 19:55:56 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/29 20:10:00 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlist_mapi(t_dlist *head, t_dlist *(*f)(int, t_dlist *), int i)
{
	t_dlist	*mapped;

	if (head)
	{
		mapped = f(i, head);
		mapped->next = ft_dlist_mapi(head->next, f, ++i);
		return (mapped);
	}
	return (NULL);
}
