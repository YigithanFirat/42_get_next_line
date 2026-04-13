/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfirat <yfirat@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:33:02 by yfirat            #+#    #+#             */
/*   Updated: 2026/04/13 17:25:32 by yfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static char	*read_from_file(int fd, char *store)
{
	char		*buffer;
	ssize_t		read_bytes;

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

static char	*get_curr_line(char *st)
{
	int		i;
	char	*str;

	i = 0;
	if (!st[i])
		return (NULL);
	while (st[i] && st[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (st[i] && st[i] != '\n')
	{
		str[i] = st[i];
		i++;
	}
	if (st[i] == '\n')
	{
		str[i] = st[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*update_state_buffer(char *store)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (store[i] && store[i] != '\n')
		i++;
	if (!store[i])
	{
		free(store);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(store) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (store[i])
		str[j++] = store[i++];
	str[j] = '\0';
	free(store);
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*store;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store = read_from_file(fd, store);
	if (!store)
		store = ft_strdup("");
	line = get_curr_line(store);
	store = update_state_buffer(store);
	return (line);
}
