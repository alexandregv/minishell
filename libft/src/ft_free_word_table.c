/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_word_table.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 00:42:56 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/28 00:43:04 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_word_table(char **words)
{
	char	**ptr;

	if (words == NULL)
		return ;
	ptr = words;
	while (*words)
		free(*words++);
	free(ptr);
}
