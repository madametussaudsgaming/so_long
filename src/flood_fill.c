/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:48:22 by rpadasia          #+#    #+#             */
/*   Updated: 2025/04/30 15:44:54 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headerfile/so_long.h"

void	flood_fill(char **m, int x, int y)
{
	if (!m[y] || !m[y][x])
		return ;
	if (m[y][x] == '1' || m[y][x] == 'F')
		return ;
	if (m[y][x] != '0' && m[y][x] != 'C' && m[y][x] != 'E' && m[y][x] != 'P')
		return ;
	m[y][x] = 'F';
	flood_fill(m, x + 1, y);
	flood_fill(m, x - 1, y);
	flood_fill(m, x, y + 1);
	flood_fill(m, x, y - 1);
}
