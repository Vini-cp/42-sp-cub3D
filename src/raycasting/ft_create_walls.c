/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 02:08:24 by vcordeir          #+#    #+#             */
/*   Updated: 2022/06/05 02:31:04 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static t_image	ft_pick_texture(t_game_set *game_set, int strip_id)
{
	t_image	image;

	if (game_set->rays[strip_id].wall_hit_content == 'C')
		image = game_set->assets->door;
	else if (game_set->rays[strip_id].was_hit_vertical)
	{
		if (game_set->rays[strip_id].is_ray_facing_right)
			image = game_set->assets->east;
		else
			image = game_set->assets->west;
	}
	else
	{
		if (game_set->rays[strip_id].is_ray_facing_up)
			image = game_set->assets->north;
		else
			image = game_set->assets->south;
	}
	return (image);
}

void	ft_create_walls(t_game_set *game_set,
						t_3d_viewer_helper *viewer,
						int strip_id,
						float x_scale)
{
	int		y;
	float	y_scale;
	t_image	image;
	int		x0;
	int		y0;
	int		start;

	y = viewer->wall_top_pixel;
	start = y;
	image = ft_pick_texture(game_set, strip_id);
	y_scale = 1.0 * (viewer->wall_bottom_pixel - viewer->wall_top_pixel) \
		/ image.height;
	while (y < viewer->wall_bottom_pixel)
	{
		if (game_set->rays[strip_id].was_hit_vertical)
			x0 = game_set->rays[strip_id].wall_hit_y - \
				(floor(game_set->rays[strip_id].wall_hit_y / TILE_SIZE) \
				* TILE_SIZE);
		else
			x0 = game_set->rays[strip_id].wall_hit_x - \
				(floor(game_set->rays[strip_id].wall_hit_x / TILE_SIZE) \
				* TILE_SIZE);
		x0 = floor((x0 % image.width) / x_scale);
		y0 = floor(((float)(y - start) / y_scale));
		game_set->color_buffer[y][strip_id] = image.buffer[y0][x0];
		y++;
	}
}
