/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd_tty.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:48:23 by aguiot--          #+#    #+#             */
/*   Updated: 2018/11/09 12:50:09 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd_tty(char const *s, int fd)
{
	ft_putstr_fd_tty(s, fd);
	ft_putchar_fd_tty('\n', fd);
}
