/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:23:51 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/29 16:24:04 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_error(char *msg, char *path, int ret)
{
	char *join;

	if (path == NULL)
		return (-1);
	if ((join = ft_strjoin(msg, path)) == NULL)
	{
		free(path);
		return (-1);
	}
	free(path);
	ft_putendl_fd(join, 2);
	free(join);
	return (ret);
}
