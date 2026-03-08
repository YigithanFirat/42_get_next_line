/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfirat <yfirat@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:10:54 by yfirat            #+#    #+#             */
/*   Updated: 2026/03/09 00:27:05 by yfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_from_file(int fd, char *store)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(store, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			free(store);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		store = ft_strjoin(store, buffer);
	}
	free(buffer);
	return (store);
}

char	*get_next_line(int fd)
{
	static char		*store;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store = read_from_file(fd, store);
	if (!store)
		return (NULL);
	line = get_curr_line(store);
	store = update_stat_buffer(store);
	return (line);
}
