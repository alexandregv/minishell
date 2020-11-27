/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:51:58 by aguiot--          #+#    #+#             */
/*   Updated: 2019/03/14 11:50:31 by aguiot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int			ft_verif_line(char **line)
{
	int ret;

	ret = (**line) ? 1 : 0;
	if (!**line)
		free(*line);
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	static char		gnl[BUFF_SIZE];
	char			*separator;
	int				nb_read;
	int				position;

	if (fd < 0 || !line || read(fd, gnl, 0) < 0 ||
			BUFF_SIZE < 1 || !(*line = ft_strnew(0)))
		return (-1);
	while (1)
	{
		if ((separator = ft_strchr(gnl, '\n')))
		{
			position = (ft_strlen(gnl) - (ft_strlen(separator)));
			*line = ft_strjoinfree(*line, gnl, position);
			ft_strncpy(gnl, &gnl[position + 1], BUFF_SIZE - position);
			return (1);
		}
		*line = ft_strjoinfree(*line, gnl, BUFF_SIZE);
		nb_read = read(fd, gnl, BUFF_SIZE);
		gnl[nb_read] = '\0';
		if (!nb_read)
			return (ft_verif_line(line));
	}
}
