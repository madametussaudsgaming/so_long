/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:26:15 by rpadasia          #+#    #+#             */
/*   Updated: 2025/04/28 20:37:48 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headerfile/so_long.h"

/* for ref: p = current position, n = new one :> FUCK YOU WERROR
*/

void	handle_exit(t_window *win, t_coord p, t_coord n)
{
	int	w;
	int	h;

	win->map[n.y][n.x] = 'P';
	win->map[p.y][p.x] = '0';
	win->won = 1;
	redraw(win);
	win->win_img = mlx_xpm_file_to_image(win->mlx, "wi.xpm", &w, &h);
	(void)w;
	(void)h;
	if (win->win_img)
		mlx_put_image_to_window(win->mlx, win->window, win->win_img, 0, 0);
	ft_printf("🎉🎉🎉We have a winner! Press ESC to exit...\n");
}

void	attempt_move(t_window *win, t_coord p, t_coord n, char dest)
{
	if (dest == 'C')
		win->items_left--;
	if (dest == 'E')
	{
		if (win->items_left == 0)
		{
			handle_exit(win, p, n);
			return ;
		}
		ft_printf("The yellow things...\n");
		return ;
	}
	if (dest == '0' || dest == 'C')
	{
		win->map[n.y][n.x] = 'P';
		win->map[p.y][p.x] = '0';
		win->moves++;
		ft_printf("Moves: %d | C left: %d\n", win->moves, win->items_left);
		redraw(win);
	}
	else
		ft_printf("Blocked at [%d,%d]\n", n.y, n.x);
}

void	move_player(char **map, char dir, t_window *win)
{
	t_coord	p;
	t_coord	n;

	if (win->won)
		return ;
	p = find_player(map);
	n = p;
	if (dir == 'W')
		n.y--;
	else if (dir == 'S' || dir == 65364)
		n.y++;
	else if (dir == 'A' || dir == 65361)
		n.x--;
	else if (dir == 'D' || dir == 65363)
		n.x++;
	if (n.y < 0 || map[n.y] == NULL || n.x < 0 || n.x >= ft_strlen(map[n.y]))
	{
		ft_printf("Out of bounds\n");
		return ;
	}
	attempt_move(win, p, n, map[n.y][n.x]);
}
