/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_ror2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:05:40 by rpadasia          #+#    #+#             */
/*   Updated: 2025/04/28 21:18:51 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headerfile/so_long.h"

char	**load_map(const char *path)
{
	int		fd;
	char	*line;
	char	**map = NULL;
	int		lines_alloc = 8;
	int		line_count = 0;

	map = malloc(sizeof(char *) * lines_alloc);
	if (!map)
		return (NULL);

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("open failed");
		free(map);
		return (NULL);
	}
	while ((line = get_next_line(fd)))
	{
		if (line_count >= lines_alloc - 1)
		{
			lines_alloc *= 2;
			char **tmp = realloc(map, sizeof(char *) * lines_alloc);
			if (!tmp)
			{
				perror("realloc failed");
				free(line);
				break;
			}
			map = tmp;
		}
		map[line_count++] = line;
	}
	map[line_count] = NULL;
	close(fd);
	return map;
}

void	load_sprites(t_window *win)
{
	int	w;
	int	h;

	win->sprites.wall = mlx_xpm_file_to_image(win->mlx, "textures/wall.xpm", &w, &h);
	win->sprites.floor = mlx_xpm_file_to_image(win->mlx, "textures/floor.xpm", &w, &h);
	win->sprites.player = mlx_xpm_file_to_image(win->mlx, "textures/player.xpm", &w, &h);
	win->sprites.items = mlx_xpm_file_to_image(win->mlx, "textures/items.xpm", &w, &h);
	win->sprites.exit = mlx_xpm_file_to_image(win->mlx, "textures/exit.xpm", &w, &h);
}