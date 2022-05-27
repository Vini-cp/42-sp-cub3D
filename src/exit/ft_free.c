/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 00:13:06 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/27 23:25:11 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_destroy_image(t_window *window, t_image *image)
{
	mlx_destroy_image(window->mlx, image->img);
}

static void	ft_free_buffer(int **buffer, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
}

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
			ft_destroy_image(game_set->window, &game_set->assets->north);
			ft_destroy_image(game_set->window, &game_set->assets->south);
			ft_destroy_image(game_set->window, &game_set->assets->west);
			ft_destroy_image(game_set->window, &game_set->assets->east);
			free(game_set->assets);
		}
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
