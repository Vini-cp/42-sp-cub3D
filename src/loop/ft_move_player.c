/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 01:44:40 by vcordeir          #+#    #+#             */
/*   Updated: 2022/06/03 23:36:40 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_move_sideways(t_player *player, t_scene *scene)
{
	float		side_step;
	float		new_x;
	float		new_y;

	side_step = player->side_direction * WALK_SPEED;
	new_x = player->x + cos(player->rotation_angle + PI / 2) * side_step;
	new_y = player->y + sin(player->rotation_angle + PI / 2) * side_step;
	if (!ft_player_collision(scene, new_x, new_y) || \
		ft_player_collision(scene, new_x, new_y) == 'O')
	{
		player->x = new_x;
		player->y = new_y;
	}
}

static void	ft_move_forward(t_player *player, t_scene *scene)
{
	float		walk_step;
	float		new_x;
	float		new_y;

	walk_step = player->walk_direction * WALK_SPEED;
	new_x = player->x + cos(player->rotation_angle + PI) * walk_step;
	new_y = player->y + sin(player->rotation_angle + PI) * walk_step;
	if (!ft_player_collision(scene, new_x, new_y) || \
		ft_player_collision(scene, new_x, new_y) == 'O')
	{
		player->x = new_x;
		player->y = new_y;
	}
}

static void	ft_spin(t_player *player)
{
	player->rotation_angle += player->turn_direction * ROT_SPEED;
	player->rotation_angle = ft_normalize_angle(player->rotation_angle);
}

void	ft_move_player(t_game_set *game_set)
{
	ft_spin(game_set->player);
	ft_move_forward(game_set->player, game_set->scene);
	ft_move_sideways(game_set->player, game_set->scene);
}
