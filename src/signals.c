/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:07:32 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/30 02:45:36 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "minishell.h"

static void	ft_handle_sig(int sig)
{
	if (sig == SIGINT || sig == SIGQUIT)
	{
		ft_putchar('\n');
		if (g_pid == -1)
			prompt(g_env);
		else
			kill(g_pid, sig);
	}
}

void		ft_signal(void)
{
	signal(SIGINT, ft_handle_sig);
	signal(SIGQUIT, ft_handle_sig);
}

int			display_sig(int ret)
{
	if (WIFEXITED(ret))
		return (WEXITSTATUS(ret));
	else if (WIFSIGNALED(ret))
	{
		if (WTERMSIG(ret) == SIGBUS)
			ft_putendl_fd("Bus Error", 2);
		else if (WTERMSIG(ret) == SIGSEGV)
			ft_putendl_fd("Seg Fault", 2);
		else if (WTERMSIG(ret) == SIGQUIT)
			ft_putendl_fd("Quitted", 2);
		else if (WTERMSIG(ret) == SIGFPE)
			ft_putendl_fd("Floating Point Exception", 2);
		else if (WTERMSIG(ret) == SIGALRM)
			ft_putendl_fd("Timed out", 2);
		else if (WTERMSIG(ret) == SIGABRT)
			ft_putendl_fd("Aborted", 2);
	}
	return (1);
}
