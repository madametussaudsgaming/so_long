/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_condensed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:21:31 by rpadasia          #+#    #+#             */
/*   Updated: 2025/04/30 01:15:56 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headerfile/so_long.h"

void	xpm_img(t_window *w, t_coord xy, char sprite)
{
	void	*tile;

	tile = NULL;
	if (sprite == '1')
		tile = w->sprites.wall;
	if (sprite == '0')
		tile = w->sprites.floor;
	if (sprite == 'C')
		tile = w->sprites.items;
	if (sprite == 'P')
		tile = w->sprites.player;
	if (sprite == 'E')
		tile = w->sprites.exit;
	if (tile)
		mlx_put_image_to_window(w->mlx, w->window, tile, xy.x, xy.y);
}

void	*xpm_conv(t_window *win, char sprite)
{
	int	w;
	int	h;

	if (sprite == '1')
		return (mlx_xpm_file_to_image(win->mlx, "textures/wall.xpm", &w, &h));
	if (sprite == '0')
		return (mlx_xpm_file_to_image(win->mlx, "textures/floor.xpm", &w, &h));
	if (sprite == 'C')
		return (mlx_xpm_file_to_image(win->mlx, "textures/items.xpm", &w, &h));
	if (sprite == 'P')
		return (mlx_xpm_file_to_image(win->mlx, "textures/player.xpm", &w, &h));
	if (sprite == 'E')
		return (mlx_xpm_file_to_image(win->mlx, "textures/exit.xpm", &w, &h));
	return (0);
}
