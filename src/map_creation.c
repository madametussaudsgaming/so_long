/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:48:48 by rpadasia          #+#    #+#             */
/*   Updated: 2025/04/28 21:53:54 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headerfile/so_long.h"

void	make_map(char **map, t_window *win, int tile_size)
{
	t_coord	xy;
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			xy.x = j * tile_size;
			xy.y = i * tile_size;
			xpm_img(win, xy, map[i][j]);
		}
	}
}