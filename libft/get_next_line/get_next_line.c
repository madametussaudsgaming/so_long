/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <rpadasia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:58:36 by rpadasia          #+#    #+#             */
/*   Updated: 2025/01/31 11:30:14 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_and_update_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_current_line(buffer);
	buffer = update_buffer_after_line(buffer);
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

char	*extract_current_line(const	char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
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
	new_buffer = ft_calloc((ft_strlen(buffer) -i + 1), sizeof(char));
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
/*
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int		fd1;
	char	*line;

	// Test 1: Reading a regular file
	fd1 = open("11.txt", O_RDONLY);
	if (fd1 < 0)
	{
		perror("Error opening test_file1.txt");
		return (1);
	}
	printf("Reading from test_file1.txt:\n");
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd1);
}*/
