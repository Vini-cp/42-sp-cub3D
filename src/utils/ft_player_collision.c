/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_collision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:58:04 by vcordeir          #+#    #+#             */
/*   Updated: 2022/06/03 18:09:30 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	ft_has_collision(char position)
{
	if (position == '1' || position == 'C' || position == 'O')
		return (position);
	return (0);
}

int	ft_player_collision(t_scene *scene, float x, float y)
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;

	x0 = floor((x - 1 - PLAYER_WIDTH / 2) / TILE_SIZE);
	y0 = floor((y - 1 - PLAYER_HEIGHT / 2) / TILE_SIZE);
	x1 = floor((x + 1 + PLAYER_WIDTH / 2) / TILE_SIZE);
	y1 = floor((y + 1 + PLAYER_HEIGHT / 2) / TILE_SIZE);
	if (ft_has_collision(scene->map[y0][x0]))
		return (ft_has_collision(scene->map[y0][x0]));
	if (ft_has_collision(scene->map[y0][x1]))
		return (ft_has_collision(scene->map[y0][x1]));
	if (ft_has_collision(scene->map[y1][x0]))
		return (ft_has_collision(scene->map[y1][x0]));
	if (ft_has_collision(scene->map[y1][x1]))
		return (ft_has_collision(scene->map[y1][x1]));
	return (0);
}
