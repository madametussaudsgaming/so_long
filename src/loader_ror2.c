/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_ror2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <rpadasia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:05:40 by rpadasia          #+#    #+#             */
/*   Updated: 2025/04/29 15:13:08 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headerfile/so_long.h"

int	count_lines(int fd)
{
	int		count;
	char	*line;

	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		count++;
		line = get_next_line(fd);
	}
	return (count);
}

char	**load_map(const char *path)
{
	int		fd;
	int		i;
	int		lines;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines = count_lines(fd);
	close(fd);
	fd = open(path, O_RDONLY);
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < lines)
		map[i++] = get_next_line(fd);
	map[i] = NULL;
	close(fd);
	return (map);
}

void	load_sprites(t_window *win)
{
	win->sprites.wall = xpm_conv(win, '1');
	win->sprites.floor = xpm_conv(win, '0');
	win->sprites.player = xpm_conv(win, 'P');
	win->sprites.items = xpm_conv(win, 'C');
	win->sprites.exit = xpm_conv(win, 'E');
}
