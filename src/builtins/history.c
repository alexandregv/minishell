/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 19:44:59 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/29 20:12:26 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_dlist	*print_node(int i, t_dlist *node)
{
	char	*itoa;

	if (node->next != NULL)
	{
		itoa = ft_itoa(i);
		ft_putchar(' ');
		ft_putstr(itoa);
		ft_putstr("  ");
		ft_putendl(node->content);
		free(itoa);
	}
	return (node);
}

int				history_builtin(t_dlist *cmds)
{
	ft_dlist_mapi(cmds, &print_node, 1);
	return (0);
}
