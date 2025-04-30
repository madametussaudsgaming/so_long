/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:38:40 by rpadasia          #+#    #+#             */
/*   Updated: 2025/04/30 20:21:00 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headerfile/so_long.h"

void	destroy_player(t_window *win)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (win->sprites.player[i])
		{
			mlx_destroy_image(win->mlx, win->sprites.player[i]);
			win->sprites.player[i] = NULL;
		}
		i++;
	}
}

void	destroy_sprites(t_window *win)
{
	if (win->sprites.wall)
	{
		mlx_destroy_image(win->mlx, win->sprites.wall);
		win->sprites.wall = NULL;
	}
	mlx_destroy_image(win->mlx, win->sprites.floor);
	win->sprites.floor = NULL;
	destroy_player(win);
	if (win->sprites.items)
	{
		mlx_destroy_image(win->mlx, win->sprites.items);
		win->sprites.items = NULL;
	}
	if (win->sprites.exit)
	{
		mlx_destroy_image(win->mlx, win->sprites.exit);
		win->sprites.exit = NULL;
	}
	if (win->sprites.enemy)
	{
		mlx_destroy_image(win->mlx, win->sprites.enemy);
		win->sprites.enemy = NULL;
	}
}

void	cleanup(t_window *win)
{
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
	destroy_sprites(win);
	if (win->window)
	{
		mlx_destroy_window(win->mlx, win->window);
		win->window = NULL;
	}
	if (win->mlx)
	{
		mlx_destroy_display(win->mlx);
		free(win->mlx);
		win->mlx = NULL;
	}
}
