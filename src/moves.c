/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpadasia <ryanpadasian@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:56:46 by rpadasia          #+#    #+#             */
/*   Updated: 2025/04/30 22:04:16 by rpadasia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headerfile/so_long.h"

void	display_moves(t_window *win)
{
	char	*moves_str;
	char	*full_str;

	moves_str = ft_itoa(win->moves);
	if (!moves_str)
		return ;
	full_str = ft_strjoin("Moves: ", moves_str);
	free(moves_str);
	if (!full_str)
		return ;
	mlx_string_put(win->mlx, win->window, 10, 10, 0x00FFFFFF, full_str);
	free(full_str);
}
