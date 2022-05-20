/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 01:35:47 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/16 01:40:03 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_draw_player(int x_start, int y_start, int color, t_window *window)
{
	int	x;
	int	y;

	y = y_start * TILE_SIZE + TILE_SIZE / 4;
	while (y < y_start * TILE_SIZE + 3 * TILE_SIZE / 4)
	{
		x = x_start * TILE_SIZE + TILE_SIZE / 4;
		while (x < x_start * TILE_SIZE + 3 * TILE_SIZE / 4)
		{
			mlx_pixel_put(window->mlx, window->win, x, y, color);
			x++;
		}
		y++;
	}
}
