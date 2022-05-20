/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 01:44:40 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/20 01:27:38 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	ft_has_collision(t_scene *scene, float x, float y)
{
	int	tile_x;
	int	tile_y;
	int	tile_x_size;
	int	tile_y_size;

	tile_x = floor(x / TILE_SIZE);
	tile_y = floor(y / TILE_SIZE);
	tile_x_size = floor((x + 10) / TILE_SIZE);
	tile_y_size = floor((y + 10) / TILE_SIZE);
	if (scene->map[tile_y][tile_x] == '1' || \
		scene->map[tile_y][tile_x_size] == '1' || \
		scene->map[tile_y_size][tile_x] == '1' || \
		scene->map[tile_y_size][tile_x_size] == '1')
		return (1);
	return (0);
}

void	ft_move_player(t_game_set *game_set)
{
	t_player	*player;
	int			new_x_position;
	int			new_y_position;
	
	player = game_set->player;
	new_x_position = player->x + player->turn_direction * WALK_SPEED;
	new_y_position = player->y + player->walk_direction * WALK_SPEED;
	if (!ft_has_collision(game_set->scene, new_x_position, new_y_position))
	{
		player->x = new_x_position;
		player->y = new_y_position;
	}
}
