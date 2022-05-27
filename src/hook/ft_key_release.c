/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_release.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 04:11:29 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/27 04:13:14 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_key_release(int keycode, t_game_set *game_set)
{
	t_player	*player;

	player = game_set->player;
	if (keycode == UP)
		player->walk_direction = 0;
	if (keycode == DOWN)
		player->walk_direction = 0;
	if (keycode == LEFT)
		player->side_direction = 0;
	if (keycode == RIGHT)
		player->side_direction = 0;
	if (keycode == LEFT_ARROW)
		player->turn_direction = 0;
	if (keycode == RIGHT_ARROW)
		player->turn_direction = 0;
	return (0);
}
