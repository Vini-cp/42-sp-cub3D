/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 03:53:33 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/20 04:03:27 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_to_image(t_image *image, char *path, t_window *window)
{
	image->img = mlx_xpm_file_to_image(window->mlx, \
					path, &image->width, &image->height);
}

void	ft_build_images(t_game_set *game_set)
{
	t_assets *assets;
	
	game_set->assets = malloc(sizeof(t_assets));
	assets = game_set->assets;
	ft_to_image(&assets->player, "./assets/player.xpm", game_set->window);
	ft_to_image(&assets->wall, "./assets/wall.xpm", game_set->window);
	ft_to_image(&assets->background, "./assets/background.xpm", game_set->window);
}
