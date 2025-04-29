/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:48:22 by rpadasia          #+#    #+#             */
/*   Updated: 2025/04/28 21:14:50 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headerfile/so_long.h"

void	flood_fill(char **map, int x, int y)
{
	if (!map[y] || map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == '0' || map[y][x] == 'C')
		map[y][x] = 'F';
	if (map[y][x] == 'E' || map[y][x] == 'P')
		map[y][x] = 'F';
	else
		return ;
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}
