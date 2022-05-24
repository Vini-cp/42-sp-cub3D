/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vertical_ray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 03:35:30 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/25 00:07:29 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_initialize_vertical_ray(t_ray *ray, t_player *player)
{
	ray->vertical.found_wall_hit = 0;
	ray->vertical.wall_hit_x = 0;
	ray->vertical.wall_hit_y = 0;
	ray->vertical.wall_content = 0;
	ray->vertical.distance = 0;
	ray->vertical.xintercept = floor(player->x / TILE_SIZE) * TILE_SIZE;
	if (ray->is_ray_facing_right)
		ray->vertical.xintercept += TILE_SIZE;
	ray->vertical.yintercept = player->y + \
		(ray->vertical.xintercept - player->x) / tan(ray->angle);
}

static void	ft_calculate_incremental_step(t_ray *ray)
{
	ray->vertical.xstep = TILE_SIZE;
	if (ray->is_ray_facing_left)
		ray->vertical.xstep *= -1;
	ray->vertical.ystep = TILE_SIZE * tan(ray->angle);
	if (ray->is_ray_facing_up && ray->vertical.ystep > 0)
		ray->vertical.ystep *= -1;
	if (ray->is_ray_facing_down && ray->vertical.ystep < 0)
		ray->vertical.ystep *= -1;
}

static void	ft_find_wall(t_ray *ray, t_scene *scene)
{
	ray->vertical.next_touch_x = ray->vertical.xintercept;
	ray->vertical.next_touch_y = ray->vertical.yintercept;
	while (ray->vertical.next_touch_x >= 0 && \
		ray->vertical.next_touch_x <= scene->map_length * TILE_SIZE && \
		ray->vertical.next_touch_y >= 0 && \
		ray->vertical.next_touch_y <= scene->map_height * TILE_SIZE)
	{
		ray->vertical.x_to_check = ray->vertical.next_touch_x;
		if (ray->is_ray_facing_left)
			ray->vertical.x_to_check += -1;
		ray->vertical.y_to_check = ray->vertical.next_touch_y;
		if (ft_has_ray_collision(scene, &ray->vertical))
			break ;
		ray->vertical.next_touch_x += ray->vertical.xstep;
		ray->vertical.next_touch_y += ray->vertical.ystep;
	}
}

void	ft_vertical_ray(t_ray *ray, t_player *player, t_scene *scene)
{
	ft_initialize_vertical_ray(ray, player);
	ft_calculate_incremental_step(ray);
	ft_find_wall(ray, scene);
}
