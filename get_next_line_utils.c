/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-13 10:02:59 by antabord          #+#    #+#             */
/*   Updated: 2025-05-13 10:02:59 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*rest_line(char *buffer)
{
	char	*sub;
	size_t	start;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	start = 0;
	if (!buffer)
		return (NULL);
	while (buffer[start] && buffer[start] != '\n')
		start++;
	if (buffer[start] == '\n')
		start++;
	len = ft_strlen(buffer + start);
	sub = malloc((len + 1) * sizeof(char));
	while (i < len)
	{
		sub[i] = buffer[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

int	ft_strlen(const char *str)
{
	int	l;

	l = 0;
	if (!str)
		return (0);
	while (str[l])
		l++;
	return (l);
}

char	*ft_get_line(char *temp)
{
	size_t	len;
	size_t	i;
	char	*line;

	i = -1;
	len = 0;
	if (!temp)
		return (NULL);
	while (temp[len] && temp[len] != '\n')
		len++;
	if (temp[len] == '\n')
		len++;
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (++i < len)
		line[i] = temp[i];
	line[i] = '\0';
	return (line);
}

char	*ft_strchr(const char *s, char *temp, char *buffer, int type)
{
	int	i;

	i = -1;
	if (type == 1)
	{
		if (buffer[0] != '\0')
		{
			temp = rest_line(buffer);
			while (temp[++i])
				buffer[i] = temp[i];
			buffer[i] = '\0';
			return (temp);
		}
		return (NULL);
	}
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == '\n')
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	result = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			result[i] = s1[i];
			i++;
		}
	}
	if (s2)
		while (s2[j])
			result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}
