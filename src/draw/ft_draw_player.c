/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 01:35:47 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/26 01:58:06 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_draw_player(int x_start, int y_start, int color, t_window *window)
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;

	y1 = (y_start + PLAYER_HEIGHT / 2) * SCALE;
	y0 = (y_start - PLAYER_HEIGHT / 2) * SCALE;
	x1 = (x_start + PLAYER_WIDTH / 2) * SCALE;
	while (y0 < y1)
	{
		x0 = (x_start - PLAYER_WIDTH / 2) * SCALE;
		while (x0 < x1)
		{
			mlx_pixel_put(window->mlx, window->win, x0, y0, color);
			x0++;
		}
		y0++;
	}
}
