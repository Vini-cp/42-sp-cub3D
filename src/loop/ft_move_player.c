/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 01:44:40 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/21 02:55:54 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static float	ft_normalize_angle(float angle)
{
	angle = fmod(angle, (2 * PI));
	if (angle < 0)
		angle = 2 * PI + angle;
	return (angle);
}

static int	ft_has_collision(t_scene *scene, float x, float y)
{
	int	tile_x;
	int	tile_y;
	int	tile_x_size;
	int	tile_y_size;

	tile_x = floor(x / TILE_SIZE);
	tile_y = floor(y / TILE_SIZE);
	tile_x_size = floor((x + PLAYER_WIDTH) / TILE_SIZE);
	tile_y_size = floor((y + PLAYER_HEIGHT) / TILE_SIZE);
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
	float		walk_step;
	float		side_step;
	float		new_x_position;
	float		new_y_position;

	player = game_set->player;
	player->rotation_angle += player->turn_direction * ROT_SPEED;
	player->rotation_angle = ft_normalize_angle(player->rotation_angle);
	walk_step = player->walk_direction * WALK_SPEED;
	new_x_position = player->x + cos(player->rotation_angle + PI) * walk_step;
	new_y_position = player->y + sin(player->rotation_angle + PI) * walk_step;
	if (!ft_has_collision(game_set->scene, new_x_position, new_y_position))
	{
		player->x = new_x_position;
		player->y = new_y_position;
	}
	side_step = player->side_direction * WALK_SPEED;
	new_x_position = player->x + cos(player->rotation_angle + PI / 2) * side_step;
	new_y_position = player->y + sin(player->rotation_angle + PI / 2) * side_step;
	if (!ft_has_collision(game_set->scene, new_x_position, new_y_position))
	{
		player->x = new_x_position;
		player->y = new_y_position;
	}
}
