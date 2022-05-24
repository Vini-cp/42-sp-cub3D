/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 01:44:40 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/24 22:12:02 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	ft_has_collision(t_scene *scene, float x, float y)
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;

	x0 = floor((x - 1 - PLAYER_WIDTH / 2)  / TILE_SIZE);
	y0 = floor((y - 1 - PLAYER_HEIGHT / 2) / TILE_SIZE);
	x1 = floor((x + 1 + PLAYER_WIDTH / 2) / TILE_SIZE);
	y1 = floor((y + 1 + PLAYER_HEIGHT / 2) / TILE_SIZE);
	if (scene->map[y0][x0] == '1' || scene->map[y0][x1] == '1' || \
		scene->map[y1][x0] == '1' || scene->map[y1][x1] == '1')
		return (1);
	return (0);
}

void	ft_move_player(t_game_set *game_set)
{
	t_player	*player;
	float		walk_step;
	float		side_step;
	float		new_x;
	float		new_y;

	player = game_set->player;
	player->rotation_angle += player->turn_direction * ROT_SPEED;
	player->rotation_angle = ft_normalize_angle(player->rotation_angle);
	walk_step = player->walk_direction * WALK_SPEED;
	new_x = player->x + cos(player->rotation_angle + PI) * walk_step;
	new_y = player->y + sin(player->rotation_angle + PI) * walk_step;
	if (!ft_has_collision(game_set->scene, new_x, new_y))
	{
		player->x = new_x;
		player->y = new_y;
	}
	side_step = player->side_direction * WALK_SPEED;
	new_x = player->x + cos(player->rotation_angle + PI / 2) * side_step;
	new_y = player->y + sin(player->rotation_angle + PI / 2) * side_step;
	if (!ft_has_collision(game_set->scene, new_x, new_y))
	{
		player->x = new_x;
		player->y = new_y;
	}
}
