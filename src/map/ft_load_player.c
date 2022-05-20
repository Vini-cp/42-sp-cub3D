/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:55:50 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/20 20:25:16 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_check_no_players(t_game_set *game_set)
{
	int	i;
	int	j;
	int	no_players;

	i = 0;
	no_players = 0;
	while (i < (game_set->scene)->map_height)
	{
		j = 0;
		while (j < (game_set->scene)->map_length)
		{
			if ((game_set->scene)->map[i][j] == 'N' || \
				(game_set->scene)->map[i][j] == 'S' || \
				(game_set->scene)->map[i][j] == 'W' || \
				(game_set->scene)->map[i][j] == 'E')
				no_players++;
			j++;
		}
		i++;
	}
	if (no_players != 1)
		ft_print_error(E_NO_PLAYER, game_set, ft_free);
}

static void	ft_load_player_positions(t_scene *scene, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (i < scene->map_height)
	{
		j = 0;
		while (j < scene->map_length)
		{
			if (scene->map[i][j] == 'N' || scene->map[i][j] == 'S' || \
				scene->map[i][j] == 'W' || scene->map[i][j] == 'E')
			{
				player->x = j * TILE_SIZE + (TILE_SIZE - PLAYER_WIDTH) / 2;
				player->y = i * TILE_SIZE + (TILE_SIZE - PLAYER_HEIGHT) / 2;
				player->initial_direction = scene->map[i][j];
			}
			j++;
		}
		i++;
	}
}

void	ft_load_player(t_game_set *game_set)
{
	ft_check_no_players(game_set);
	game_set->player = malloc(sizeof(t_player));
	ft_load_player_positions(game_set->scene, game_set->player);
	(game_set->player)->turn_direction = 0;
    (game_set->player)->walk_direction = 0;
	if ((game_set->player)->initial_direction == 'E')
    	(game_set->player)->rotation_angle = 0;
	else if ((game_set->player)->initial_direction == 'S')
    	(game_set->player)->rotation_angle = PI / 2;
	else if ((game_set->player)->initial_direction == 'W')
    	(game_set->player)->rotation_angle = PI;
	else if ((game_set->player)->initial_direction == 'N')
    	(game_set->player)->rotation_angle = 3 * PI / 2;
}
