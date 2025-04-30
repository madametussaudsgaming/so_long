/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:04:00 by rpadasia          #+#    #+#             */
/*   Updated: 2025/04/30 17:46:04 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headerfile/so_long.h"

t_mapsize	get_map_size(char **map)
{
	t_mapsize	size = {0, 0};
	if (!map || !map[0])
		return (size);

	size.y = 0;
	while (map[size.y])
		size.y++;

	size.x = strlen(map[0]);
	return (size);
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

	if (!map_is_valid(map))
	{
		ft_printf("Error, unreachables detected.\n");
		free_char_array(map);
		return (1);
	}

	if (!(validate_map(map)))
	{
		ft_printf("Error, invalid configuration\n");
		free_char_array(map);
		return (1);
	}
	t_mapsize map_size = get_map_size(map);
	int width = map_size.x * 50;
	int height = map_size.y * 50;

	win.map = map;
	win.items_left = count_collectibles(map);
	win.moves = 0;
	win.mlx = mlx_init();
	if (!win.mlx)
		return (1);

	win.window = mlx_new_window(win.mlx, width - 50, height, "Step One!");
	mlx_img.img = mlx_new_image(win.mlx, width - 50, height);
	win.img = &mlx_img;

	load_sprites(&win);
	load_player_idle(&win);
	make_map(map, &win, 50);
	mlx_key_hook(win.window, drax, &win);
	mlx_hook(win.window, 17, 0, x_button, &win);
	mlx_loop_hook(win.mlx, update, &win);
	mlx_loop(win.mlx);
	free_char_array(map);
	cleanup(&win);
	return (0);
}
