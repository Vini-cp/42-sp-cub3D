/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 00:13:06 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/20 04:11:10 by vcordeir         ###   ########.fr       */
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
		{
			mlx_destroy_image((game_set->window)->mlx, (game_set->assets)->player.img);
			mlx_destroy_image((game_set->window)->mlx, (game_set->assets)->wall.img);
			mlx_destroy_image((game_set->window)->mlx, (game_set->assets)->background.img);
			free(game_set->assets);
		}
		if (game_set->window)
		{
			mlx_destroy_display((game_set->window)->mlx);
			free((game_set->window)->mlx);
			free(game_set->window);
		}
	}
}
