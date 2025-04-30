/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:04:00 by rpadasia          #+#    #+#             */
/*   Updated: 2025/04/30 22:16:59 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headerfile/so_long.h"

// int	main(int argc, char *argv[])
// {
// 	t_window 	win = {0};
//     t_data 		mlx_img = {0};
// 	char		**map;

// 	if (argc != 2)
// 	{
// 		ft_printf("Usage: %s <map.ber>\n", argv[0]);
// 		return (1);
// 	}
// 	map = load_map(argv[1]);
// 	if (!map)
// 	{
// 		ft_printf("Error, Doesn't Exist.\n");
// 		return (1);
// 	}
// 	if (!all_reachable(map))
// 	{
// 		ft_printf("Error, Unreachables Detected.\n");
// 		free_char_array(map);
// 		return (1);
// 	}
// 	if (!(validate_map(map)))
// 	{
// 		ft_printf("Error, Invalid Configuration\n");
// 		free_char_array(map);
// 		return (1);
// 	}
// 	t_mapsize map_size = get_map_size(map);
// 	int width = map_size.x * 50;
// 	int height = map_size.y * 50;

// 	win.map = map;
// 	win.items_left = count_collectibles(map);
// 	win.moves = 0;
// 	win.mlx = mlx_init();
// 	if (!win.mlx)
// 		return (1);

// 	win.window = mlx_new_window(win.mlx, width - 50, height, "bug.exe");
// 	mlx_img.img = mlx_new_image(win.mlx, width - 50, height);
// 	win.img = &mlx_img;

// 	load_sprites(&win);
// 	load_player_idle(&win);
// 	make_map(map, &win, 50);
// 	mlx_key_hook(win.window, drax, &win);
// 	mlx_hook(win.window, 17, 0, x_button, &win);
// 	mlx_loop_hook(win.mlx, update, &win);
// 	mlx_loop(win.mlx);
// 	free_char_array(map);
// 	cleanup(&win);
// 	return (0);
// }

int	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Usage: %s <map.ber>\n", argv[0]);
		return (0);
	}
	return (1);
}

int	validate_input_map(char *path, char ***out_map)
{
	char	**map;

	map = load_map(path);
	if (!map)
	{
		ft_printf("Error, Doesn't Exist.\n");
		return (0);
	}
	if (!all_reachable(map))
	{
		ft_printf("Error, Unreachables Detected.\n");
		free_char_array(map);
		return (0);
	}
	if (!validate_map(map))
	{
		ft_printf("Error, Invalid Configuration\n");
		free_char_array(map);
		return (0);
	}
	*out_map = map;
	return (1);
}

int	init_game_window(t_window *win, t_data *mlx_img, t_mapsize size)
{
	int	width;
	int	height;

	width = size.x * 50;
	height = size.y * 50;
	win->mlx = mlx_init();
	if (!win->mlx)
		return (0);
	win->window = mlx_new_window(win->mlx, width - 50, height, "bug.exe");
	mlx_img->img = mlx_new_image(win->mlx, width - 50, height);
	win->img = mlx_img;
	return (1);
}

void	run_game_loop(t_window *win, t_data *mlx_img)
{
	load_sprites(win);
	load_player_idle(win);
	make_map(win->map, win, 50);
	mlx_key_hook(win->window, drax, win);
	mlx_hook(win->window, 17, 0, x_button, win);
	mlx_loop_hook(win->mlx, update, win);
	mlx_loop(win->mlx);
	free_char_array(win->map);
	cleanup(win);
}

int	main(int argc, char **argv)
{
	t_window	win;
	t_data		mlx_img;
	t_mapsize	map_size;

	ft_memset(&win, 0, sizeof(t_window));
	ft_memset(&mlx_img, 0, sizeof(t_data));
	if (!check_args(argc, argv))
		return (1);
	if (!validate_input_map(argv[1], &win.map))
		return (1);
	map_size = get_map_size(win.map);
	win.items_left = count_collectibles(win.map);
	win.moves = 0;
	if (!init_game_window(&win, &mlx_img, map_size))
		return (1);
	run_game_loop(&win, &mlx_img);
	return (0);
}
