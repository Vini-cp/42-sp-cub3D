/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 23:46:55 by vcordeir          #+#    #+#             */
/*   Updated: 2022/06/03 23:50:19 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_destroy_image(t_window *window, t_image *image)
{
	mlx_destroy_image(window->mlx, image->img);
}

void	ft_free_assets(t_game_set *game_set)
{
	ft_destroy_image(game_set->window, &game_set->assets->north);
	ft_destroy_image(game_set->window, &game_set->assets->south);
	ft_destroy_image(game_set->window, &game_set->assets->west);
	ft_destroy_image(game_set->window, &game_set->assets->east);
	free(game_set->assets);
}
