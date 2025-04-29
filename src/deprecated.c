/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deprecated.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:45:00 by rpadasia          #+#    #+#             */
/*   Updated: 2025/04/28 21:04:33 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headerfile/so_long.h"

void	pixel_place(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bitspp / 8));
	*(unsigned int *)dst = color;
}

void	draw_tile(t_coord xy, t_data *img, int size, int color)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < size)
	{
		while (col < size)
		{
			pixel_place(img, (xy.x + row), (xy.y + col), color);
			col++;
		}
		col = 0;
		row++;
	}
}
