/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_del_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:08:33 by aguiot--          #+#    #+#             */
/*   Updated: 2019/03/19 05:42:50 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlist_del_node(t_dlist **node, void (*del)(void *, size_t))
{
	if (del)
		del((*node)->content, (*node)->content_size);
	free((*node)->content);
	(*node)->next = NULL;
	(*node)->prev = NULL;
	free(*node);
	*node = NULL;
}
