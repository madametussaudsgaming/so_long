/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:04:00 by rpadasia          #+#    #+#             */
/*   Updated: 2025/04/21 14:27:46 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../headerfile/so_long.h"
#include <stdio.h>
#include <math.h>

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
    printf("Key pressed: %d\n", keycode);
    t_window *win = (t_window *)param;

    if (keycode == 65307) // ESC key 2. Schedule cleanup for the next loop iteration
		mlx_loop_end(win->mlx);
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

int	main(void)
{
	t_window win = {0};
    t_data mlx_img = {0};

    win.mlx = mlx_init();
    if (!win.mlx) return (1);

    win.window = mlx_new_window(win.mlx, 960, 480, "Step One!");
    mlx_img.img = mlx_new_image(win.mlx, 1920, 1080);
    mlx_img.addr = mlx_get_data_addr(mlx_img.img, &mlx_img.bitspp, &mlx_img.line_len, &mlx_img.endian);
    win.img = &mlx_img;

	char *map[] = {
		"11111111111",
		"10000000001",
		"10011100001",
		"1001P100001",
		"10010100001",
		"10000000001",
		"1000E000001",
		"10000000001",
		"10000000001",
		"11111111111",
		NULL
	};

	make_map(map, &mlx_img, 50);
	mlx_put_image_to_window(win.mlx, win.window, mlx_img.img, 0, 0);

	mlx_key_hook(win.window, drax, &win);
    mlx_loop(win.mlx);

    // Cleanup AFTER loop has fully ended
    cleanup(&win);
    return (0);
}
