/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfirat <yfirat@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:25:42 by yfirat            #+#    #+#             */
/*   Updated: 2026/02/26 13:48:41 by yfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		s1_length;
	size_t		s2_length;
	char		*sp;

	if (!s1 || !s2)
		return (NULL);
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	sp = (char *)malloc(s1_length + s2_length + 1);
	if (sp == NULL)
		return (NULL);
	ft_memmove(sp, s1, s1_length);
	ft_memmove((char *)sp + s1_length, s2, s2_length);
	sp[s1_length + s2_length] = '\0';
	return (sp);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*pp;
	size_t			i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	i = 0;
	if (size != 0 && nmemb > ((size_t) - 1 / size))
		return (NULL);
	pp = malloc(nmemb * size);
	if (pp == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		pp[i] = 0;
		i++;
	}
	return ((void *)pp);
}
