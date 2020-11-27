/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_del_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:09:09 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/28 00:44:39 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_dlist_del_at(t_dlist **head, void (*del)(void *, size_t), size_t index)
{
	t_dlist	*node;

	node = ft_dlist_get_at(*head, index);
	ft_dlist_del_node(&node, del);
}
