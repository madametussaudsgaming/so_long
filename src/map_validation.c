/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:48:56 by rpadasia          #+#    #+#             */
/*   Updated: 2025/04/30 14:50:47 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headerfile/so_long.h"

int	top_bottom_valid(char **map, int i)
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

void	count_elements(char **map, int *num, int len)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j] && map[i][j] != '\n')
		{
			if ((map[i][j]) == 'P')
				num[0]++;
			if ((map[i][j]) == 'C')
				num[1]++;
			if ((map[i][j]) == 'E')
				num[2]++;
		}
		if (j != len || map[i][0] != '1' || map[i][len - 1] != '1')
		{
			num[3] = -1;
			return ;
		}
	}
	num[3] = i;
}

int	validate_map(char **map)
{
	int	len;
	int	num[4];

	num[0] = 0;
	num[1] = 0;
	num[2] = 0;
	num[3] = 0;
	len = ft_mapstrlen(map);
	count_elements(map, num, len);
	if (num[3] == -1)
		return (0);
	if (num[0] != 1 || num[1] < 1 || num[2] < 1)
		return (0);
	return (top_bottom_valid(map, num[3]));
}

int	check_unreachable(char **copy)
{
	int	y;
	int	x;

	y = 0;
	while (copy[y])
	{
		x = 0;
		while (copy[y][x])
		{
			if (copy[y][x] == 'C' || copy[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

// int		top_bottom_valid(char **map, int i)
// {
// 	int	len;
// 	int	j;

// 	len = ft_mapstrlen(map);
// 	j = 0;
// 	while (j < len)
// 	{
// 		if (map[0][j] != '1' || map[i - 1][j] != '1')
// 			return (0);
// 		j++;
// 	}
// 	return (1);
// }

// int		validate_map(char **map)
// {
// 	int i;
// 	int j;
// 	int e;
// 	int p;
// 	int c;
// 	int	len;

// 	i = -1;
// 	e = 0;
// 	p = 0;
// 	c = 0;
// 	len = ft_mapstrlen(map);
// 	while (map[++i])
// 	{
// 		j = -1;
// 		while(map[i][++j] && map[i][j] != '\n')
// 		{
// 			if ((map[i][j]) == 'P')
// 				p++;
// 			if ((map[i][j]) == 'C')
// 				c++;
// 			if ((map[i][j]) == 'E')
// 				e++;
// 		}
// 		if (j != len || map[i][0] != '1' || map[i][len - 1] != '1')
// 			return (0);
// 	}
// 	if ((p != 1) || (c < 1) || (e < 1))
// 		return (0);
// 	return (top_bottom_valid(map, i));
// }