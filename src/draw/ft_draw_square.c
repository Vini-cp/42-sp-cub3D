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

	y = y_start * TILE_SIZE;
	while (y < y_start * TILE_SIZE + TILE_SIZE)
	{
		x = x_start * TILE_SIZE;
		while (x < x_start * TILE_SIZE + TILE_SIZE)
		{
			mlx_pixel_put(window->mlx, window->win, x, y, color);
			x++;
		}
		y++;
	}
}
