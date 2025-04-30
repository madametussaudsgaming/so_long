/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:27:59 by rpadasia          #+#    #+#             */
/*   Updated: 2025/04/30 21:57:22 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headerfile/so_long.h"

void	redraw(t_window *win)
{
	mlx_clear_window(win->mlx, win->window);
	if (win->won && win->win_img)
	{
		mlx_put_image_to_window(win->mlx, win->window, win->win_img, 0, 0);
		return ;
	}
	make_map(win->map, win, 50);
	display_moves(win);
}

int	update(void *param)
{
	t_window	*win;

	win = (t_window *)param;
	if (++win->frame_counter >= 10)
	{
		win->frame_counter = 0;
		win->player_frame++;
		if (win->player_frame >= 2)
			win->player_frame = 0;
		redraw(win);
	}
	return (0);
}
