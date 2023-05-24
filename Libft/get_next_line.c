/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:10:09 by hferjani          #+#    #+#             */
/*   Updated: 2022/06/28 11:16:36 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	line = NULL;
	line = ft_strjoin(line, buffer);
	bytes_read = BUFFER_SIZE;
	while (!(ft_strchr(line, '\n') || bytes_read != BUFFER_SIZE))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
	}
	if (!line[0])
		return (free (line), NULL);
	else
		ft_line(line, buffer);
	return (line);
}
