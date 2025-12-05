/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-13 09:29:21 by antabord          #+#    #+#             */
/*   Updated: 2025-05-13 09:29:21 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			bytes_read;
	static char	buffer[BUFFER_SIZE + 1];
	char		*old_buffer;
	char		*temp;

	bytes_read = 1;
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	temp = ft_strchr(NULL, NULL, buffer, 1);
	while (bytes_read > 0 && !ft_strchr(temp, NULL, NULL, 0))
	{
		old_buffer = temp;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(temp), NULL);
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(temp, buffer);
		free(old_buffer);
	}
	if (!temp || *temp == '\0')
		return (free(temp), NULL);
	old_buffer = ft_get_line(temp);
	return (free(temp), old_buffer);
}
/* int	main(void)
{
	int		fd;
	char	*line;

	fd = open("arquivo1.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Erro ao abrir o arquivo");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
} */
