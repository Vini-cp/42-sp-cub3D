/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 03:00:23 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/25 02:36:28 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_ray_face_direction(t_ray *ray)
{
	ray->is_ray_facing_down = ray->angle > 0 && ray->angle < PI;
	ray->is_ray_facing_up = !ray->is_ray_facing_down;
	ray->is_ray_facing_right = ray->angle < 0.5 * PI || ray->angle > 1.5 * PI;
	ray->is_ray_facing_left = !ray->is_ray_facing_right;
}

static void	ft_define_distances(t_ray *ray, t_player *player)
{
	if (ray->horizontal.found_wall_hit)
		ray->horizontal.distance = \
			ft_point_distance(player->x, player->y, \
				ray->horizontal.wall_hit_x, ray->horizontal.wall_hit_y);
	else
		ray->horizontal.distance = FLT_MAX;
	if (ray->vertical.found_wall_hit)
		ray->vertical.distance = \
			ft_point_distance(player->x, player->y, \
				ray->vertical.wall_hit_x, ray->vertical.wall_hit_y);
	else
		ray->vertical.distance = FLT_MAX;
}

static void	ft_find_min_distance(t_ray *ray)
{
	if (ray->vertical.distance < ray->horizontal.distance)
	{
		ray->distance = ray->vertical.distance;
		ray->wall_hit_x = ray->vertical.wall_hit_x;
		ray->wall_hit_y = ray->vertical.wall_hit_y;
		ray->wall_hit_content = ray->vertical.wall_content;
		ray->was_hit_vertical = 1;
	}
	else
	{
		ray->distance = ray->horizontal.distance;
		ray->wall_hit_x = ray->horizontal.wall_hit_x;
		ray->wall_hit_y = ray->horizontal.wall_hit_y;
		ray->wall_hit_content = ray->horizontal.wall_content;
		ray->was_hit_vertical = 0;
	}
}

static void	cast_ray(t_ray *ray, t_player *player, t_scene *scene)
{
	ft_ray_face_direction(ray);
	ft_horizontal_ray(ray, player, scene);
	ft_vertical_ray(ray, player, scene);
	ft_define_distances(ray, player);
	ft_find_min_distance(ray);
}

void	ft_cast_rays(t_game_set *game_set)
{
	float	field_of_view;
	float	ray_angle;
	int		strip_id;

	game_set->number_of_rays = 350;
	game_set->rays = malloc(game_set->number_of_rays * sizeof(t_ray));
	field_of_view = FOV_ANGLE * PI / 180;
	ray_angle = (game_set->player)->rotation_angle - (field_of_view / 2);
	strip_id = 0;
	while (strip_id < game_set->number_of_rays)
	{
		game_set->rays[strip_id].angle = ft_normalize_angle(ray_angle);
		cast_ray(&game_set->rays[strip_id], game_set->player, game_set->scene);
		ray_angle += field_of_view / (game_set->number_of_rays - 1);
		strip_id++;
	}
}
