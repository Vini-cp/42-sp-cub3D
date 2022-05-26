/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 00:52:21 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/26 01:52:47 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_render_minimap(t_window *window, t_scene *scene)
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
				ft_draw_square(j, i, WHITE, window);
			else if (scene->map[i][j] != '1' && scene->map[i][j] != ' ')
				ft_draw_square(j, i, GRAY, window);
			j++;
		}
		i++;
	}
}

static void	ft_render_player(t_window *window, t_player *player)
{
	ft_draw_player(player->x, player->y, YELLOW, window);
}

static void	ft_draw_color_buffer(t_game_set *game_set)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < LENGTH)
		{
			if (j >= (game_set->scene)->map_length * TILE_SIZE * SCALE || \
				i >= (game_set->scene)->map_height * TILE_SIZE * SCALE)
				mlx_pixel_put((game_set->window)->mlx, \
					(game_set->window)->win, j, i, \
					game_set->color_buffer[i][j]);
			j++;
		}
		i++;
	}
}

void	ft_render(t_game_set *game_set)
{
	ft_draw_color_buffer(game_set);
	ft_render_minimap(game_set->window, game_set->scene);
	ft_render_player(game_set->window, game_set->player);
	ft_draw_rays(game_set, RED);
	ft_draw_line(game_set->window, game_set->player, 25, DARK);
}
