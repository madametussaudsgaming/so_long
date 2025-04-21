/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <rpadasia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:55:01 by rpadasia          #+#    #+#             */
/*   Updated: 2025/02/02 14:28:33 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buffers[MAX_FDS];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffers[fd] = read_and_update_buffer(fd, buffers[fd]);
	if (!buffers[fd])
		return (NULL);
	line = extract_current_line(buffers[fd]);
	buffers[fd] = update_buffer_after_line(buffers[fd]);
	return (line);
}

char	*read_and_update_buffer(int fd, char *existing_buffer)
{
	char	*temp_buffer;
	int		char_reader;

	if (!existing_buffer)
		existing_buffer = ft_calloc(1, 1);
	temp_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	char_reader = 1;
	while (char_reader > 0)
	{
		char_reader = read(fd, temp_buffer, BUFFER_SIZE);
		if (char_reader == -1)
		{
			free(temp_buffer);
			free(existing_buffer);
			return (NULL);
		}
		temp_buffer[char_reader] = 0;
		existing_buffer = append_to_buffer(existing_buffer, temp_buffer);
		if (ft_strchr(temp_buffer, '\n'))
			break ;
	}
	free (temp_buffer);
	return (existing_buffer);
}

char	*extract_current_line(const char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && (buffer[i] != '\n'))
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && (buffer[i] == '\n'))
		line[i++] = '\n';
	return (line);
}

char	*update_buffer_after_line(char *buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	free(buffer);
	return (new_buffer);
}

char	*append_to_buffer(char *existing_buffer, char *buffy)
{
	char	*new_buffer;

	new_buffer = ft_strjoin(existing_buffer, buffy);
	free(existing_buffer);
	return (new_buffer);
}

/*#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd1, fd2, fd3;
	char *line;

	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
	{
		perror("Error opening files");
		return (1);
	}

    // Read and print lines alternately from all file descriptors
    for (int i = 0; i < 5; i++)
    {
        if ((line = get_next_line(fd1)))
        {
            printf("FD1: %s", line);
            free(line);
        }
        if ((line = get_next_line(fd2)))
        {
            printf("FD2: %s", line);
            free(line);
        }
        if ((line = get_next_line(fd3)))
        {
            printf("FD3: %s", line);
            free(line);
        }
    }
	line = get_next_line(1515);
	printf("FD4: %s", line);
	free (line);

    // Close all file descriptors
    close(fd1);
    close(fd2);
    close(fd3);

    return (0);
}*/
