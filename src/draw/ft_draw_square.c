/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 01:00:43 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/16 01:30:44 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_draw_square(int x_start, int y_start, int color, t_window *window)
{
	int	x;
	int	y;
	int	x_end;
	int	y_end;

	y = y_start * TILE_SIZE * SCALE;
	y_end = (y_start * TILE_SIZE + TILE_SIZE) * SCALE;
	x_end = (x_start * TILE_SIZE + TILE_SIZE) * SCALE;
	while (y < y_end)
	{
		x = x_start * TILE_SIZE * SCALE;
		while (x < x_end)
		{
			mlx_pixel_put(window->mlx, window->win, x, y, color);
			x++;
		}
		y++;
	}
}
