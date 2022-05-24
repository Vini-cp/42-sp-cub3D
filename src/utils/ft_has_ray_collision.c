/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_ray_collision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 21:51:34 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/25 00:27:33 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_set_collision(t_ray_helper *ray)
{
	ray->wall_hit_x = ray->next_touch_x;
	ray->wall_hit_y = ray->next_touch_y;
	ray->found_wall_hit = 1;
}

int	ft_has_ray_collision(t_scene *scene, t_ray_helper *ray)
{
	int	tile_x;
	int	tile_y;

	tile_x = floor(ray->x_to_check / TILE_SIZE);
	tile_y = floor(ray->y_to_check / TILE_SIZE);
	if (ray->x_to_check < 0 || tile_x >= scene->map_length || \
		ray->y_to_check < 0 || tile_y >= scene->map_height)
	{
		ft_set_collision(ray);
		return (1);
	}
	else if (scene->map[tile_y][tile_x] == '1')
	{
		ft_set_collision(ray);
		ray->wall_content = '1';
		return (1);
	}
	return (0);
}
