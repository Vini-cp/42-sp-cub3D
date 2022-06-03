/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 01:44:40 by vcordeir          #+#    #+#             */
/*   Updated: 2022/06/03 18:17:55 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
	if (!ft_player_collision(game_set->scene, new_x, new_y) || \
		ft_player_collision(game_set->scene, new_x, new_y) == 'O')
	{
		player->x = new_x;
		player->y = new_y;
	}
	side_step = player->side_direction * WALK_SPEED;
	new_x = player->x + cos(player->rotation_angle + PI / 2) * side_step;
	new_y = player->y + sin(player->rotation_angle + PI / 2) * side_step;
	if (!ft_player_collision(game_set->scene, new_x, new_y) || \
		ft_player_collision(game_set->scene, new_x, new_y) == 'O')
	{
		player->x = new_x;
		player->y = new_y;
	}
}
