/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 00:35:10 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/28 00:35:12 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exit_builtin(char **argv)
{
	if (argv[1] != NULL)
	{
		if (ft_str_is_numeric(argv[1]))
			exit(ft_atoi(argv[1]));
		exit(127);
	}
	return (258);
}
