/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 03:53:33 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/26 02:05:36 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_create_color_buffer(t_game_set *game_set)
{
	int	i;

	i = 0;
	game_set->color_buffer = malloc(HEIGHT * sizeof(int *));
	while (i < HEIGHT)
	{
		game_set->color_buffer[i] = malloc(LENGTH * sizeof(int));
		i++;
	}
}

static void	ft_clear_color_buffer(t_game_set *game_set)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < LENGTH)
		{
			game_set->color_buffer[i][j] = 0xFFFFFFFF;
			j++;
		}
		i++;
	}
}

static void	ft_to_image(t_image *image, char *path, t_window *window)
{
	image->img = mlx_xpm_file_to_image(window->mlx, \
					path, &image->width, &image->height);
}

void	ft_build_images(t_game_set *game_set)
{
	t_assets	*assets;

	assets = game_set->assets;
	ft_to_image(&assets->player, PLAYER, game_set->window);
	ft_to_image(&assets->wall, WALL, game_set->window);
	ft_to_image(&assets->background, BACKGROUND, game_set->window);
	ft_create_color_buffer(game_set);
	ft_clear_color_buffer(game_set);
}
