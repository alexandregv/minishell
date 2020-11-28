/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 00:34:57 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/28 00:34:57 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo_builtin(char **argv, char **env)
{
	char	*str;

	if ((str = ft_join_table(argv + 1, " ")) == NULL)
		return (-1);
	ft_putendl(str);
	free(str);
	return (0);
	(void)env;
}
