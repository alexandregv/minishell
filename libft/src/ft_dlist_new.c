/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:05:50 by aguiot--          #+#    #+#             */
/*   Updated: 2019/03/19 07:13:08 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int
	fill_node(t_dlist *node, const void *content, size_t content_size, int copy)
{
	if (copy)
	{
		if ((node->content = ft_memalloc(content_size)) == NULL)
		{
			ft_memdel((void **)&node);
			return (-1);
		}
		ft_memcpy(node->content, content, content_size);
		node->content_size = content_size;
	}
	else
	{
		node->content = (void *)content;
		node->content_size = content_size;
	}
	return (0);
}

t_dlist
	*ft_dlist_new(const void *content, size_t content_size, int copy)
{
	t_dlist	*node;

	if ((node = (t_dlist *)malloc(sizeof(t_dlist))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		node->content = NULL;
		node->content_size = 0;
	}
	else if (fill_node(node, content, content_size, copy) == -1)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
