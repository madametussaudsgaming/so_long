/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:48:56 by rpadasia          #+#    #+#             */
/*   Updated: 2025/04/28 21:05:05 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headerfile/so_long.h"

int		top_bottom_valid(char **map, int i)
{
	int	len;
	int	j;

	len = ft_mapstrlen(map);
	j = 0;
	while (j < len)
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int		validate_map(char **map)
{
	int i;
	int j;
	int e;
	int p;
	int c;
	int	len;

	i = -1;
	e = 0;
	p = 0;
	c = 0;
	len = ft_mapstrlen(map);
	while (map[++i])
	{
		j = -1;
		while(map[i][++j] && map[i][j] != '\n')
		{
			if ((map[i][j]) == 'P')
				p++;
			if ((map[i][j]) == 'C')
				c++;
			if ((map[i][j]) == 'E')
				e++;
		}
		if (j != len || map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
	}
	if ((p != 1) || (c < 1) || (e < 1))
		return (0);
	return (top_bottom_valid(map, i));
}

bool	map_is_valid(char **map)
{
	int		x;
	int		y;
	char	**copy;

	copy = map_dup(map);
	if (!copy)
		return false;
	for (y = 0; copy[y]; y++)
		for (x = 0; copy[y][x]; x++)
			if (copy[y][x] == 'P')
				flood_fill(copy, x, y);

	for (y = 0; copy[y]; y++)
	{
		for (x = 0; copy[y][x]; x++)
		{
			if (copy[y][x] == 'C' || copy[y][x] == 'E')
			{
				free_char_array(copy);
				return false;
			}
		}
	}
	free_char_array(copy);
	return true;
}