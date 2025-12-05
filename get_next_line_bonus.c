/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-13 09:45:51 by antabord          #+#    #+#             */
/*   Updated: 2025-06-13 09:45:51 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	int			bytes_read;
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*old_buffer;
	char		*temp;

	bytes_read = 1;
	if (BUFFER_SIZE < 1 || fd < 0 || fd >= FOPEN_MAX)
		return (NULL);
	temp = ft_strchr(NULL, NULL, buffer[fd], 1);
	while (bytes_read > 0 && !ft_strchr(temp, NULL, NULL, 0))
	{
		old_buffer = temp;
		bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(temp), NULL);
		buffer[fd][bytes_read] = '\0';
		temp = ft_strjoin(temp, buffer[fd]);
		free(old_buffer);
	}
	if (!temp || *temp == '\0')
		return (free(temp), NULL);
	old_buffer = ft_get_line(temp);
	return (free(temp), old_buffer);
}
/* int	main(void)
{
	int	fd1 = open("arquivo1.txt", O_RDONLY);
	int	fd2 = open("arquivo2.txt", O_RDONLY);
	int	fd3 = open("arquivo3.txt", O_RDONLY);
	char *line1;
	char *line2;
	char *line3;

	while (1)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		line3 = get_next_line(fd3);

		if (!line1 && !line2 && !line3 )
			break;
		if (line1)
		{
			printf("arq1_ %s", line1);
			free(line1);
		}
		if (line2)
		{
			printf("arq2_ %s", line2);
			free(line2);
		}
		if(line3)
		{
			printf("arq3_ %s", line3);
			free(line3);
		}
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
} */