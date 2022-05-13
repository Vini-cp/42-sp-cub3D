/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 00:13:06 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/13 21:26:24 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_free(void *param)
{
	t_game_set	*game_set;

	game_set = (t_game_set *)param;
	if (game_set)
	{
		if (game_set->scene)
			ft_free_scene(game_set->scene);
		if (game_set->player)
			free(game_set->player);
	}
}
