/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 00:14:47 by hferjani          #+#    #+#             */
/*   Updated: 2022/06/28 11:29:07 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	line = NULL;
	line = ft_strjoin(line, buffer[fd]);
	bytes_read = BUFFER_SIZE;
	while (!(ft_strchr(line, '\n') || bytes_read != BUFFER_SIZE))
	{	
		bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		buffer[fd][bytes_read] = '\0';
		line = ft_strjoin(line, buffer[fd]);
	}
	if (!line[0])
		return (free (line), NULL);
	else
		ft_line(line, buffer[fd]);
	return (line);
}
