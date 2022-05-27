/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 03:53:33 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/27 23:47:00 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_create_color_buffer(t_game_set *game_set)
{
	int	i;

	i = 0;
	game_set->color_buffer = malloc(game_set->window_height * sizeof(int *));
	while (i < game_set->window_height)
	{
		game_set->color_buffer[i] = malloc(game_set->window_width * sizeof(int));
		i++;
	}
}

static void	ft_clear_color_buffer(t_game_set *game_set)
{
	int	i;
	int	j;

	i = 0;
	while (i < game_set->window_height)
	{
		j = 0;
		while (j < game_set->window_width)
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
	image->address = mlx_get_data_addr(image->img, &image->bits_per_pixel, \
		&image->size_line, &image->endian);
}

void	ft_build_images(t_game_set *game_set)
{
	t_assets	*assets;
	t_scene		*scene;

	assets = game_set->assets;
	scene = game_set->scene;
	ft_to_image(&assets->north,scene->north_texture, game_set->window);
	ft_to_image(&assets->south,scene->south_texture, game_set->window);
	ft_to_image(&assets->west,scene->west_texture, game_set->window);
	ft_to_image(&assets->east,scene->east_texture, game_set->window);
	ft_create_color_buffer(game_set);
	ft_clear_color_buffer(game_set);
}
