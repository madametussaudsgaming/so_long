/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:32:25 by rpadasia          #+#    #+#             */
/*   Updated: 2025/04/21 12:12:24 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <mlx.h>

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
}	t_window;

typedef struct s_game {
	t_window 	win;
	char		**map;
	t_coord		player_pos;
	int			moves;
	int			items;
}	t_game;

void make_map(char **map, t_data *img, int tile_size);
void init_player_pos(t_game *game);
int drax(int keycode, void *param);
void move_player(t_game *game, int dx, int dy);
bool	map_is_valid(char **map);
char	**map_dup(char **map);
void	flood_fill(char **map, int x, int y);
void	draw_tile(t_coord xy, t_data *img, int size, int color);
void	pixel_place(t_data *img, int x, int y, int color);
