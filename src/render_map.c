/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:48:42 by rpadasia          #+#    #+#             */
/*   Updated: 2025/04/28 17:09:12 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headerfile/so_long.h"

void	render_map(char **map, t_window *win, int tile_size)
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
				mlx_put_image_to_window(win->mlx, win->window, win->sprites.wall, xy.x, xy.y);
			else if (map[i][j] == '0')
				mlx_put_image_to_window(win->mlx, win->window, win->sprites.floor, xy.x, xy.y);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(win->mlx, win->window, win->sprites.player, xy.x, xy.y);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(win->mlx, win->window, win->sprites.items, xy.x, xy.y);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(win->mlx, win->window, win->sprites.exit, xy.x, xy.y);
			j++;
		}
		i++;
	}
}