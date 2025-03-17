/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:39:53 by achu              #+#    #+#             */
/*   Updated: 2025/03/09 18:32:53 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*find_cur_line(char *buffer)
{
	int		i;
	int		len;
	char	*line;

	i = 0;
	len = 0;
	while (buffer[len] != '\0' && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		len++;
	if (len <= 0)
		return (NULL);
	line = (char *)ft_calloc((len + 1), sizeof(char));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*find_next_line(char *buffer)
{
	int		i;
	int		len;
	char	*line;

	i = 0;
	len = 0;
	while (buffer[len] != '\0' && buffer[len] != '\n')
		len++;
	if (!buffer[len])
		return (free(buffer), NULL);
	line = (char *)ft_calloc((ft_strlen(buffer) - len + 1), sizeof(char));
	if (!line)
		return (NULL);
	len++;
	while (buffer[len + i] != '\0')
	{
		line[i] = buffer[len + i];
		i++;
	}
	line[i] = '\0';
	free(buffer);
	return (line);
}

char	*get_cur_line(int fd, char *line)
{
	char	*buffer;
	char	*temp;
	int		readbytes;

	if (!line)
		line = (char *)ft_calloc(1, 1);
	if (!line)
		return (NULL);
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	readbytes = 1;
	while (readbytes > 0 && !ft_strchr(buffer, '\n'))
	{
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes < 0)
			return (free(buffer), free(line), NULL);
		buffer[readbytes] = '\0';
		temp = ft_strjoin(line, buffer);
		if (!temp)
			return (free(buffer), free(line), NULL);
		free(line);
		line = temp;
	}
	return (free(buffer), line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(buffer), buffer = NULL, NULL);
	buffer = get_cur_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = find_cur_line(buffer);
	buffer = find_next_line(buffer);
	return (line);
}
