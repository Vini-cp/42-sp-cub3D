/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3d_viewer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 03:50:10 by vcordeir          #+#    #+#             */
/*   Updated: 2022/06/05 02:16:45 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_initialize(t_game_set *game_set,
						t_3d_viewer_helper *viewer,
						int strip_id,
						float field_of_view)
{
	viewer->perpendicular_distance = game_set->rays[strip_id].distance * \
		cos(game_set->rays[strip_id].angle - \
		(game_set->player)->rotation_angle);
	viewer->distance_projected = \
		(game_set->window_width / 2) / tan(field_of_view / 2);
	viewer->projected_wall_height = \
		(TILE_SIZE / viewer->perpendicular_distance) * \
		viewer->distance_projected;
	viewer->wall_strip_height = (int)viewer->projected_wall_height;
	viewer->wall_top_pixel = \
		(game_set->window_height / 2) - (viewer->wall_strip_height / 2);
	if (viewer->wall_top_pixel < 0)
		viewer->wall_top_pixel = 0;
	viewer->wall_bottom_pixel = \
		(game_set->window_height / 2) + (viewer->wall_strip_height / 2);
	if (viewer->wall_bottom_pixel > game_set->window_height)
		viewer->wall_bottom_pixel = game_set->window_height;
}

static void	ft_create_ceiling(t_game_set *game_set,
							t_3d_viewer_helper *viewer,
							int strip_id)
{
	int	y;

	y = 0;
	while (y < viewer->wall_top_pixel)
	{
		game_set->color_buffer[y][strip_id] = (game_set->assets)->ceiling_color;
		y++;
	}
}

static void	ft_create_floor(t_game_set *game_set,
							t_3d_viewer_helper *viewer,
							int strip_id)
{
	int	y;

	y = viewer->wall_bottom_pixel;
	while (y < game_set->window_height)
	{
		game_set->color_buffer[y][strip_id] = (game_set->assets)->floor_color;
		y++;
	}
}

void	ft_3d_viewer(t_game_set *game_set)
{
	int					strip_id;
	float				field_of_view;
	float				x_scale;
	t_3d_viewer_helper	viewer;

	field_of_view = FOV_ANGLE * PI / 180;
	strip_id = 0;
	x_scale = game_set->assets->north.width / TILE_SIZE;
	while (strip_id < game_set->number_of_rays)
	{
		ft_initialize(game_set, &viewer, strip_id, field_of_view);
		ft_create_ceiling(game_set, &viewer, strip_id);
		ft_create_walls(game_set, &viewer, strip_id, x_scale);
		ft_create_floor(game_set, &viewer, strip_id);
		strip_id++;
	}
}
