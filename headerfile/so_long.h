/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:32:25 by rpadasia          #+#    #+#             */
/*   Updated: 2025/04/24 16:59:26 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../libft/get_next_line/get_next_line_bonus.h"
# include "../libft/ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <stdbool.h>
# include <string.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bitspp;
	int		line_len;
	int		endian;
}	t_data;

typedef struct s_coord {
	int		x;
	int		y;
}	t_coord;

typedef struct s_mapsize {
	int		x;
	int		y;
}	t_mapsize;

typedef struct s_window {
	void	*mlx;
	void	*window;
	t_data	*img;
	char	**map;
	int		moves;
	int		items_left;
	int		won;
	void	*win_img;
}	t_window;

void make_map(char **map, t_data *img, int tile_size);
int drax(int keycode, void *param);
bool	map_is_valid(char **map);
char	**map_dup(char **map);
void	flood_fill(char **map, int x, int y);
void	draw_tile(t_coord xy, t_data *img, int size, int color);
void	pixel_place(t_data *img, int x, int y, int color);

#endif