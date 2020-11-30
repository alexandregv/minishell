/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_word_table.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 00:42:56 by aguiot--          #+#    #+#             */
/*   Updated: 2020/11/30 01:49:10 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_word_table(char ***words)
{
	int		i;

	if (*words == NULL)
		return ;
	i = 0;
	while ((*words)[i])
	{
		free((*words)[i]);
		(*words)[i++] = NULL;
	}
	free(*words);
	*words = NULL;
}
