/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 04:11:17 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/27 04:12:58 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_key_press(int keycode, t_game_set *game_set)
{
	t_player	*player;

	player = game_set->player;
	if (keycode == ESC)
		ft_exit_hook(game_set);
	if (keycode == UP)
		player->walk_direction = -1;
	if (keycode == DOWN)
		player->walk_direction = +1;
	if (keycode == LEFT)
		player->side_direction = -1;
	if (keycode == RIGHT)
		player->side_direction = +1;
	if (keycode == LEFT_ARROW)
		player->turn_direction = -1;
	if (keycode == RIGHT_ARROW)
		player->turn_direction = +1;
	return (0);
}
