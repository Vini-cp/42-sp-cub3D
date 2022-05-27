/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 04:11:44 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/27 04:13:39 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_mouse_move(int x, int y, t_game_set *game_set)
{
	t_player	*player;

	player = game_set->player;
	if (x > 0 && x < game_set->window_width / 2 - 100)
		player->turn_direction = -0.5;
	if (x > game_set->window_width / 2 + 100 && \
		x < game_set->window_width)
		player->turn_direction = +0.5;
	if (x > game_set->window_width / 2 - 100 && \
		x < game_set->window_width / 2 + 100)
		player->turn_direction = 0;
	(void)y;
	return (0);
}
