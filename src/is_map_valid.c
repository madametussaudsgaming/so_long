/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 01:18:51 by rpadasia          #+#    #+#             */
/*   Updated: 2025/04/30 14:50:25 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headerfile/so_long.h"

void	flooder(char **copy)
{
	int	x;
	int	y;

	y = 0;
	while (copy[y])
	{
		x = 0;
		while (copy[y][x])
		{
			if (copy[y][x] == 'P')
				flood_fill(copy, x, y);
			x++;
		}
		y++;
	}
}

bool	map_is_valid(char **map)
{
	char	**copy;

	copy = map_dup(map);
	if (!copy)
		return (false);
	flooder(copy);
	if (!check_unreachable(copy))
	{
		free_char_array(copy);
		return (false);
	}
	free_char_array(copy);
	return (true);
}
