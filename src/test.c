/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:04:00 by rpadasia          #+#    #+#             */
/*   Updated: 2025/04/24 17:22:28 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headerfile/so_long.h"

/*
ALPHA RED GREEND BLUE
*/
void	pixel_place(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bitspp / 8));
	*(unsigned int*)dst = color;
}

void	draw_tile(t_coord xy, t_data *img, int size, int color)
{
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			pixel_place(img, (xy.x + row), (xy.y + col), color);
		}
	}
}

void	flood_fill(char **map, int x, int y)
{
	if (!map[y] || map[y][x] == '1' || map[y][x] == 'F')
		return;
	if (map[y][x] == '0' || map[y][x] == 'C' || map[y][x] == 'E' || map[y][x] == 'P')
		map[y][x] = 'F';
	else
		return;
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

char	**map_dup(char **map)
{
	int		i;
	char	**copy;

	for (i = 0; map[i]; i++);
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return NULL;
	for (i = 0; map[i]; i++)
		copy[i] = strdup(map[i]);
	copy[i] = NULL;
	return copy;
}

bool	map_is_valid(char **map)
{
	int		x, y;
	char	**copy = map_dup(map);

	if (!copy)
		return false;
	for (y = 0; copy[y]; y++)
		for (x = 0; copy[y][x]; x++)
			if (copy[y][x] == 'P')
				flood_fill(copy, x, y);

	for (y = 0; copy[y]; y++)
	{
		for (x = 0; copy[y][x]; x++)
		{
			if (copy[y][x] == 'C' || copy[y][x] == 'E')
			{
				int i = 0;
				while (copy[i])
					free(copy[i++]);
				free(copy);
				return false;
			}
		}
	}
	int i = 0;
	while (copy[i])
		free(copy[i++]);
	free(copy);
	return true;
}

void	make_map(char **map, t_data *img, int tile_size)
{
	t_coord	xy;
	int		i = 0;

	while (map[i])
	{
		int j = 0;
		while (map[i][j])
		{
			xy.x = j * tile_size;
			xy.y = i * tile_size;
			if (map[i][j] == '1')
				draw_tile(xy, img, tile_size, 0x00333333);
			else if (map[i][j] == '0')
				draw_tile(xy, img, tile_size, 0x00CCCCCC);
			else if (map[i][j] == 'P')
				draw_tile(xy, img, tile_size, 0x0000FF00);
			else if (map[i][j] == 'C')
				draw_tile(xy, img, tile_size, 0x00FFFF00);
			else if (map[i][j] == 'E')
				draw_tile(xy, img, tile_size, 0x00FF0000);
			j++;
		}
		i++;
	}
	write(1, "map made\n", 10);
	if (map_is_valid(map))
		printf("✅ Map is valid!\n");
	else
		printf("❌ Map is invalid!\n");
}

int drax(int keycode, void *param)
{
    t_window *win = (t_window *)param;

    if (keycode == 65307)
		mlx_loop_end(win->mlx);
	else if (keycode == 'w' || keycode == 65362)
		move_player(win->map, 'W', win);
	else if (keycode == 'a' || keycode == 65361)
		move_player(win->map, 'A', win);
	else if (keycode == 's' || keycode == 65364)
		move_player(win->map, 'S', win);
	else if (keycode == 'd' || keycode == 65363)
		move_player(win->map, 'D', win);

    return (0);
}

void cleanup(t_window *win)
{
    // 1. Destroy image if it exists
    if (win->img && win->img->img)
    {
        mlx_destroy_image(win->mlx, win->img->img);
        win->img->img = NULL;
    }

	if (win->win_img)
	{
		mlx_destroy_image(win->mlx, win->win_img);
		win->win_img = NULL;
	}

    // 2. Destroy window if it exists
    if (win->window)
    {
        mlx_destroy_window(win->mlx, win->window);
        win->window = NULL;
    }

    // 3. Linux-specific cleanup
    #ifdef __linux__
        if (win->mlx)
        {
            mlx_destroy_display(win->mlx);
            free(win->mlx);
            win->mlx = NULL;
        }
    #endif
}

int		validate_map(char **map)
{
	int i;
	int j;
	int e;
	int p;
	int c;

	i = 0;
	j = 0;
	e = 0;
	p = 0;
	c = 0;
	while (map[i])
	{
		while(map[i][j])
		{
			if ((map[i][j]) == 'P')
				p++;
			if ((map[i][j]) == 'C')
				c++;
			if ((map[i][j]) == 'E')
				e++;
			j++;
		}
		j = 0;
		i++;
	}
	if ((p != 1) || (c < 1) || (e < 1))
		return (0);
	return (1);
}

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

t_coord find_player(char	**map)
{
	t_coord pos;
	pos.x = -1;
	pos.y = -1;

	for (int y = 0; map[y]; y++)
	{
		for (int x = 0; map[y][x]; x++)
		{
			if (map[y][x] == 'P')
			{
				pos.x = x;
				pos.y = y;
				return pos;
			}
		}
	}
	return pos;
}

void	render_map(char **map, t_data *img, int tile_size)
{
	t_coord xy;
	int i = 0;

	while (map[i])
	{
		int j = 0;
		while (map[i][j])
		{
			xy.x = j * tile_size;
			xy.y = i * tile_size;
			if (map[i][j] == '1')
				draw_tile(xy, img, tile_size, 0x00333333); // wall
			else if (map[i][j] == '0')
				draw_tile(xy, img, tile_size, 0x00CCCCCC); // floor
			else if (map[i][j] == 'P')
				draw_tile(xy, img, tile_size, 0x0000FF00); // player
			else if (map[i][j] == 'C')
				draw_tile(xy, img, tile_size, 0x00FFFF00); // collectible
			else if (map[i][j] == 'E')
				draw_tile(xy, img, tile_size, 0x00FF0000); // exit
			j++;
		}
		i++;
	}
}

void	move_player(char **map, char dir, t_window *win)
{
	if (win->won)
		return;
	t_coord p = find_player(map);
	/*temp coordinates*/
	int nx = p.x;
	int ny = p.y;

	if (dir == 'W')
		ny--;
	else if (dir == 'S' || dir == 65364)
		ny++;
	else if (dir == 'A' || dir == 65361)
		nx--;
	else if (dir == 'D' || dir == 65363)
		nx++;

	if (ny < 0 || map[ny] == NULL || nx < 0 || nx >= (int)strlen(map[ny]))
	{
		printf("Out of bounds\n");
		return;
	}

	char dest = map[ny][nx];

	if (dest == '1')
		return;

	if (dest == 'C')
		win->items_left--;

	if (dest == 'E')
	{
		if (win->items_left == 0)
		{
			map[ny][nx] = 'P';
			map[p.y][p.x] = '0';
			win->won = 1;
			render_map(map, win->img, 50);
			void *img = mlx_xpm_file_to_image(win->mlx, "you_win.xpm", &(int){0}, &(int){0});
			if (img)
			{
				win->win_img = img;
				mlx_put_image_to_window(win->mlx, win->window, img, 0, 0);
			}
			printf("🎉🎉🎉We have a winner! Press ESC to exit...\n");
			return;
		}
		else
		{
			printf("The yellow things...\n");
			return;
		}
	}

	if (dest == '0' || dest == 'C')
	{
		map[ny][nx] = 'P';
		map[p.y][p.x] = '0';
		win->moves++;
		printf("Moved %c to [%d,%d] | Moves: %d | C left: %d\n", dir, ny, nx, win->moves, win->items_left);

		render_map(map, win->img, 50);
		mlx_put_image_to_window(win->mlx, win->window, win->img->img, 0,0);
	}
	else
		ft_printf("Blocked at [%d,%d]\n", ny, nx);
	for (int i = 0; map[i]; i++)
		printf("%s", map[i]);
	printf("\n");
}

int	count_collectibles(char **map)
{
	int	i;
	int	j;
	int c;

	i = 0;
	c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

int	main(int argc, char *argv[])
{
	t_window 	win = {0};
    t_data 		mlx_img = {0};
	char		**map;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <map.ber>\n", argv[0]);
		return (1);
	}
	map = load_map(argv[1]);

	if (!(validate_map(map)))
	{
		fprintf(stderr, "Failed to load map\n");
		for (int i = 0; map[i]; i++)
			free(map[i]);
		free(map);
		return (1);
	}
	win.map = map;
	win.items_left = count_collectibles(map);
	win.moves = 0;
    win.mlx = mlx_init();
    if (!win.mlx)
		return (1);

    win.window = mlx_new_window(win.mlx, 960, 480, "Step One!");
    mlx_img.img = mlx_new_image(win.mlx, 1920, 1080);
    mlx_img.addr = mlx_get_data_addr(mlx_img.img, &mlx_img.bitspp, &mlx_img.line_len, &mlx_img.endian);
    win.img = &mlx_img;


	make_map(map, &mlx_img, 50);

	mlx_put_image_to_window(win.mlx, win.window, mlx_img.img, 0, 0);
	mlx_key_hook(win.window, drax, &win);

    mlx_loop(win.mlx);
	for (int i = 0; map[i]; i++)
		free(map[i]);
	free(map);
    // Cleanup AFTER loop has fully ended
    cleanup(&win);
    return (0);
}
