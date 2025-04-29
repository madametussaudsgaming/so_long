/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_destroyers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:37:58 by rpadasia          #+#    #+#             */
/*   Updated: 2025/04/28 17:08:52 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headerfile/so_long.h"

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

int	x_button(void *param)
{
	t_window *win = (t_window *)param;
	mlx_loop_end(win->mlx);
	return (0);
}