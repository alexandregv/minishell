/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 00:35:44 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/28 21:27:48 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		pwd_builtin(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 255);
	if (cwd == NULL)
	{
		ft_putendl("minishell: pwd: error with current working directory)");
		return (1);
	}
	else
	{
		ft_putendl(cwd);
		free(cwd);
		return (0);
	}
}
