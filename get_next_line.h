/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-14 12:05:36 by antabord          #+#    #+#             */
/*   Updated: 2025-05-14 12:05:36 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*rest_line(char *buffer);
char	*ft_get_line(char *temp);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, char *temp, char *buffer, int type);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *str);

#endif
