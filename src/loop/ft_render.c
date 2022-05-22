/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 00:52:21 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/22 02:35:51 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_put_image(t_window *window, void *img, int x, int y)
{
	mlx_put_image_to_window(window->mlx, window->win, img, x, y);
}

static void	ft_render_minimap(t_scene *scene,
							t_window *window,
							t_assets *assets)
{
	int	i;
	int	j;

	i = 0;
	while (i < scene->map_height)
	{
		j = 0;
		while (j < scene->map_length)
		{
			if (scene->map[i][j] == '1')
				ft_put_image(window, \
					(assets->wall).img, j * TILE_SIZE, i * TILE_SIZE);
			else if (scene->map[i][j] != '1' && scene->map[i][j] != ' ')
				ft_put_image(window, \
					(assets->background).img, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

static void	ft_render_player(t_window *window,
							t_assets *assets,
							t_player *player)
{
	ft_put_image(window, (assets->player).img, player->x, player->y);
}

void	ft_render(t_game_set *game_set)
{
	ft_render_minimap(game_set->scene, game_set->window, game_set->assets);
	ft_render_player(game_set->window, game_set->assets, game_set->player);
	ft_draw_line(game_set->window, game_set->player, 25, DARK);
}
