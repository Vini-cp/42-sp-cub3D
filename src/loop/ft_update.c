/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 01:12:28 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/25 05:01:45 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_update(t_game_set *game_set)
{
	ft_move_player(game_set);
	ft_cast_rays(game_set);
	ft_3d_viewer(game_set);
	ft_render(game_set);
	return (0);
}
