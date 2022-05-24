/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_horizontal_ray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 03:28:31 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/25 00:05:56 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_initialize_horizontal_ray(t_ray *ray, t_player *player)
{
	ray->horizontal.found_wall_hit = 0;
	ray->horizontal.wall_hit_x = 0;
	ray->horizontal.wall_hit_y = 0;
	ray->horizontal.wall_content = 0;
	ray->horizontal.distance = 0;
	ray->horizontal.yintercept = floor(player->y / TILE_SIZE) * TILE_SIZE;
	if (ray->is_ray_facing_down)
		ray->horizontal.yintercept += TILE_SIZE;
	ray->horizontal.xintercept = player->x + \
		(ray->horizontal.yintercept - player->y) / tan(ray->angle);
}

static void	ft_calculate_incremental_step(t_ray *ray)
{
	ray->horizontal.ystep = TILE_SIZE;
	if (ray->is_ray_facing_up)
		ray->horizontal.ystep *= -1;
	ray->horizontal.xstep = TILE_SIZE / tan(ray->angle);
	if (ray->is_ray_facing_left && ray->horizontal.xstep > 0)
		ray->horizontal.xstep *= -1;
	if (ray->is_ray_facing_right && ray->horizontal.xstep < 0)
		ray->horizontal.xstep *= -1;
}

static void	ft_find_wall(t_ray *ray, t_scene *scene)
{
	ray->horizontal.next_touch_x = ray->horizontal.xintercept;
	ray->horizontal.next_touch_y = ray->horizontal.yintercept;
	while (ray->horizontal.next_touch_x >= 0 && \
		ray->horizontal.next_touch_x <= scene->map_length * TILE_SIZE && \
		ray->horizontal.next_touch_y >= 0 && \
		ray->horizontal.next_touch_y <= scene->map_height * TILE_SIZE)
	{
		ray->horizontal.x_to_check = ray->horizontal.next_touch_x;
		ray->horizontal.y_to_check = ray->horizontal.next_touch_y;
		if (ray->is_ray_facing_up)
			ray->horizontal.y_to_check += -1;
		if (ft_has_ray_collision(scene, &ray->horizontal))
			break ;
		ray->horizontal.next_touch_x += ray->horizontal.xstep;
		ray->horizontal.next_touch_y += ray->horizontal.ystep;
	}
}

void	ft_horizontal_ray(t_ray *ray, t_player *player, t_scene *scene)
{
	ft_initialize_horizontal_ray(ray, player);
	ft_calculate_incremental_step(ray);
	ft_find_wall(ray, scene);
}
