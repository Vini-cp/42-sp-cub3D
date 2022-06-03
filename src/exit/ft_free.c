/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 00:13:06 by vcordeir          #+#    #+#             */
/*   Updated: 2022/06/03 23:48:57 by vcordeir         ###   ########.fr       */
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
		if (game_set->assets)
			ft_free_assets(game_set);
		if (game_set->window)
		{
			mlx_destroy_display((game_set->window)->mlx);
			free((game_set->window)->mlx);
			free(game_set->window);
		}
		if (game_set->rays)
			free(game_set->rays);
		if (game_set->color_buffer)
			ft_free_buffer(game_set->color_buffer, game_set->window_height);
	}
}
